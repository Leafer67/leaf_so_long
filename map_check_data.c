/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 10:25:07 by lloison           #+#    #+#             */
/*   Updated: 2022/12/07 18:08:01 by lloison          ###   ########.fr       */
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

void	data_to_tiles(t_map *map, t_list **map_lines)
{
	int		i;
	t_list	*lst;

	lst = *map_lines;
	map->tiles = malloc(sizeof(char *) * map->size.y);
	if (map->tiles == 0)
		exit_program(0, map_lines, map, "Malloc error");
	i = 0;
	while (i < map->size.y)
	{
		map->tiles[i] = ft_substr(lst->content, 0, map->size.x);
		if (map->tiles[i] == 0)
			exit_program(0, map_lines, map, "Malloc error");
		lst = lst->next;
		i++;
	}
}

void	get_start_pos(t_map *map)
{
	int		i;
	int		j;
	t_bool	pos_found;

	pos_found = FALSE;
	i = -1;
	while (++i < map->size.y)
	{
		j = -1;
		while (++j < map->size.x)
		{
			if (map->tiles[i][j] == 'P')
			{
				if (pos_found)
					exit_program(0, 0, map, "Multiple start position found");
				pos_found = TRUE;
				map->start_pos.x = j;
				map->start_pos.y = i;
			}
		}
	}
	if (pos_found == FALSE)
		exit_program(0, 0, map, "No start position found");
}

void	get_end_pos(t_map *map)
{
	int		i;
	int		j;
	t_bool	pos_found;

	pos_found = FALSE;
	i = -1;
	while (++i < map->size.y)
	{
		j = -1;
		while (++j < map->size.x)
		{
			if (map->tiles[i][j] == 'E')
			{
				if (pos_found)
					exit_program(0, 0, map, "Multiple end position found");
				pos_found = TRUE;
				map->exit_pos.x = j;
				map->exit_pos.y = i;
			}
		}
	}
	if (pos_found == FALSE)
		exit_program(0, 0, map, "No end position found");
}

void	check_file_name(char *file)
{
	int	last_index;

	last_index = ft_strlen(file) - 1;
	if (last_index < 3)
		exit_program(0, 0, 0, "File format is invalid, use .ber");
	if (file[last_index] != 'r' || file[last_index - 1] != 'e'
		|| file[last_index - 2] != 'b' || file[last_index - 3] != '.')
		exit_program(0, 0, 0, "File format is invalid, use .ber");
}
