/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_data2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:14:26 by lloison           #+#    #+#             */
/*   Updated: 2022/12/07 18:08:07 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	exit_program(int fd, t_list **list, t_map *map, char *error_msg)
{
	if (fd != 0)
		close(fd);
	if (list)
		ft_lstclear(list, free);
	if (map != 0)
		free_map(map);
	ft_printf("Error\n");
	ft_printf("%s\n", error_msg);
	exit(0);
}

void	get_nb_items_enemies(t_map *map)
{
	int		i;
	int		j;
	int		items_count;
	int		enemies_count;

	items_count = 0;
	enemies_count = 0;
	i = -1;
	while (++i < map->size.y)
	{
		j = -1;
		while (++j < map->size.x)
		{
			if (map->tiles[i][j] == 'C')
				items_count++;
			if (map->tiles[i][j] == 'U' || map->tiles[i][j] == 'D'
				|| map->tiles[i][j] == 'R' || map->tiles[i][j] == 'L')
				enemies_count++;
		}
	}
	if (items_count == 0)
		exit_program(0, 0, map, "No collectibles found (must have at least 1)");
	map->nb_items = items_count;
	map->nb_enemies = enemies_count;
}

void	get_items_pos(t_map *map)
{
	int	i;
	int	j;
	int	curr_item_i;

	map->items_pos = ft_calloc(map->nb_items, sizeof(t_pos));
	if (map->items_pos == 0)
		exit_program(0, 0, map, "Malloc error");
	curr_item_i = 0;
	i = -1;
	while (curr_item_i < map->nb_items)
	{
		while (++i < map->size.y)
		{
			j = -1;
			while (++j < map->size.x)
			{
				if (map->tiles[i][j] == 'C')
				{
					map->items_pos[curr_item_i].x = j;
					map->items_pos[curr_item_i].y = i;
					curr_item_i++;
				}
			}
		}
	}
}

static void	update_enemy(t_map *map, int index, t_pos pos, char direction)
{
	map->enemies_pos[index] = pos;
	if (direction == 'U')
		map->enemies_dir[index] = up;
	if (direction == 'D')
		map->enemies_dir[index] = down;
	if (direction == 'R')
		map->enemies_dir[index] = right;
	if (direction == 'L')
		map->enemies_dir[index] = left;
	map->tiles[pos.y][pos.x] = '0';
}

void	get_enemies_pos_dir(t_map *map)
{
	int	i;
	int	j;
	int	enemy_i;

	map->enemies_pos = ft_calloc(map->nb_enemies, sizeof(t_pos));
	map->enemies_dir = ft_calloc(map->nb_enemies, sizeof(t_direction));
	if (map->enemies_pos == 0 || map->enemies_dir == 0)
		exit_program(0, 0, map, "Malloc error");
	enemy_i = 0;
	i = -1;
	while (enemy_i < map->nb_enemies)
	{
		while (++i < map->size.y)
		{
			j = -1;
			while (++j < map->size.x)
			{
				if (map->tiles[i][j] == 'U' || map->tiles[i][j] == 'D'
					|| map->tiles[i][j] == 'R' || map->tiles[i][j] == 'L')
					update_enemy(map, enemy_i++, pos(j, i), map->tiles[i][j]);
			}
		}
	}
}
