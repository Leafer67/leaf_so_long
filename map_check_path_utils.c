/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:46:14 by lloison           #+#    #+#             */
/*   Updated: 2022/11/21 10:46:36 by lloison          ###   ########.fr       */
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
		free_map(&map);
	ft_printf("Error\n");
	ft_printf("%s\n", error_msg);
	exit(0);
}

t_bool	**init_visited(t_map *map)
{
	t_bool	**visited;
	int		i;

	visited = ft_calloc(sizeof(t_bool *), map->size.y);
	if (!visited)
		exit_program(0, map, "Malloc error");
	i = 0;
	while (i < map->size.y)
	{
		visited[i] = ft_calloc(sizeof(t_bool), map->size.x);
		if (!visited[i])
			exit_program(visited, map, "Malloc error");
		i++;
	}
	return (visited);
}

void	reset_visited(t_bool **visited, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->size.y)
	{
		j = 0;
		while (j < map->size.x)
		{
			visited[i][j] = 0;
			j++;
		}
		i++;
	}
}
