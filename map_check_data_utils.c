/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_data_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:54:01 by lloison           #+#    #+#             */
/*   Updated: 2022/11/28 11:57:29 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	exit_program(t_data *data, t_map *map, char *error_msg)
{
	if (data != 0)
		free_data(&data);
	if (map != 0)
		free_map(&map);
	ft_printf("Error\n");
	ft_printf("%s\n", error_msg);
	exit(0);
}

void	check_if_map_is_enclosed(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (++j < map->size.x)
		if (map->tiles[i][j] != '1')
			exit_program(0, map, "Map must be enclosed by walls");
	i = -1;
	j = 0;
	while (++i < map->size.y)
		if (map->tiles[i][j] != '1')
			exit_program(0, map, "Map must be enclosed by walls");
	i = map->size.y - 1;
	j = -1;
	while (++j < map->size.x)
		if (map->tiles[i][j] != '1')
			exit_program(0, map, "Map must be enclosed by walls");
	i = -1;
	j = map->size.x - 1;
	while (++i < map->size.y)
		if (map->tiles[i][j] != '1')
			exit_program(0, map, "Map must be enclosed by walls");
}

int	get_item_index(t_data *data, t_pos item_pos)
{
	int	i;

	i = 0;
	while (i < data->map->nb_items)
	{
		if (item_pos.x == data->map->items_pos[i].x
			&& item_pos.y == data->map->items_pos[i].y)
			return (i);
		i++;
	}
	exit_program(data, 0, "Trying to access inexistent item");
	return (0);
}
