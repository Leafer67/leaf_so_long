/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 10:28:18 by lloison           #+#    #+#             */
/*   Updated: 2022/12/07 18:08:14 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	exit_program(t_bool **visited, t_map *map, char *error_msg)
{
	int	i;

	i = 0;
	if (visited)
	{
		while (visited[i] && i < map->size.y)
		{
			free(visited[i]);
			i++;
		}
		free(visited);
	}
	if (map != 0)
		free_map(map);
	ft_printf("Error\n");
	ft_printf("%s\n", error_msg);
	exit(0);
}

t_bool	search_for_end(int x, int y, t_map *map, t_bool **visited)
{
	if (x < 0 || x >= map->size.x || y < 0 || y >= map->size.y)
		return (FALSE);
	if (visited[y][x] == TRUE)
		return (FALSE);
	visited[y][x] = TRUE;
	if (map->tiles[y][x] == '1')
		return (FALSE);
	if (map->tiles[y][x] == 'E')
		return (TRUE);
	if (search_for_end(x - 1, y, map, visited) == TRUE)
		return (TRUE);
	if (search_for_end(x + 1, y, map, visited) == TRUE)
		return (TRUE);
	if (search_for_end(x, y - 1, map, visited) == TRUE)
		return (TRUE);
	if (search_for_end(x, y + 1, map, visited) == TRUE)
		return (TRUE);
	return (FALSE);
}

t_bool	search_for_item(t_pos start_pos, t_pos end_pos,
	t_map *map, t_bool **visited)
{
	if (start_pos.x < 0 || start_pos.x >= map->size.x
		|| start_pos.y < 0 || start_pos.y >= map->size.y)
		return (FALSE);
	if (visited[start_pos.y][start_pos.x] == TRUE)
		return (FALSE);
	visited[start_pos.y][start_pos.x] = TRUE;
	if (map->tiles[start_pos.y][start_pos.x] == '1')
		return (FALSE);
	if (start_pos.x == end_pos.x && start_pos.y == end_pos.y)
		return (TRUE);
	if (search_for_item(pos(start_pos.x - 1, start_pos.y),
			end_pos, map, visited) == TRUE)
		return (TRUE);
	if (search_for_item(pos(start_pos.x + 1, start_pos.y),
			end_pos, map, visited) == TRUE)
		return (TRUE);
	if (search_for_item(pos(start_pos.x, start_pos.y - 1),
			end_pos, map, visited) == TRUE)
		return (TRUE);
	if (search_for_item(pos(start_pos.x, start_pos.y + 1),
			end_pos, map, visited) == TRUE)
		return (TRUE);
	return (FALSE);
}

void	has_valid_path(t_map *map)
{
	t_bool	**visited;
	int		i;

	visited = init_visited(map);
	i = 0;
	while (i < map->nb_items)
	{
		if (search_for_item(map->start_pos, map->items_pos[i],
				map, visited) == FALSE)
			exit_program(visited, map, "No valid path found to an item");
		reset_visited(visited, map);
		i++;
	}
	if (search_for_end(map->start_pos.x, map->start_pos.y,
			map, visited) == FALSE)
		exit_program(visited, map, "No valid path found from start to exit");
	i = 0;
	while (i < map->size.y)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}
