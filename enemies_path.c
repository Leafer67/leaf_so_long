/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:47:34 by lloison           #+#    #+#             */
/*   Updated: 2022/12/07 14:20:59 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_data.h"
#include "enemy_behavior.h"
#include "parsing.h"

static void	exit_program(t_queue *queue, t_data *data,
	t_list *toclear, char *error_msg)
{
	if (queue)
		free_queue(&queue, free);
	if (data)
		free_data(&data);
	if (toclear)
		ft_lstclear(&toclear, free);
	ft_printf("%s\n", error_msg);
	exit(0);
}

static void	enqueue_all_adjacent_tile2(t_data *d, t_queue **queue,
	t_node *p, t_bool **visited)
{
	t_pos	c;

	c = p->position;
	if (c.x + 1 < d->map->size.x && d->map->tiles[c.y][c.x + 1] != '1')
	{
		if (!visited[c.y][c.x + 1])
			enqueue(d, queue, pos(c.x + 1, c.y), p);
		if (c.y - 1 > 0 && d->map->tiles[c.y - 1][c.x + 1] != '1')
			if (!visited[c.y - 1][c.x + 1])
				enqueue(d, queue, pos(c.x + 1, c.y - 1), p);
		if (c.y + 1 < d->map->size.y && d->map->tiles[c.y + 1][c.x + 1] != '1')
			if (!visited[c.y + 1][c.x + 1])
				enqueue(d, queue, pos(c.x + 1, c.y + 1), p);
	}
	if (c.y - 1 > 0 && d->map->tiles[c.y - 1][c.x] != '1')
		if (!visited[c.y - 1][c.x])
			enqueue(d, queue, pos(c.x, c.y - 1), p);
	if (c.y + 1 < d->map->size.y && d->map->tiles[c.y + 1][c.x] != '1')
		if (!visited[c.y + 1][c.x])
			enqueue(d, queue, pos(c.x, c.y + 1), p);
}

static void	enqueue_all_adjacent_tile(t_data *d, t_queue **queue,
	t_node *p, t_bool **visited)
{
	t_pos	c;

	c = p->position;
	if (c.x - 1 > 0 && d->map->tiles[c.y][c.x - 1] != '1')
	{
		if (!visited[c.y][c.x - 1])
			enqueue(d, queue, pos(c.x - 1, c.y), p);
		if (c.y - 1 > 0 && d->map->tiles[c.y - 1][c.x - 1] != '1')
			if (!visited[c.y - 1][c.x - 1])
				enqueue(d, queue, pos(c.x - 1, c.y - 1), p);
		if (c.y + 1 < d->map->size.y && d->map->tiles[c.y + 1][c.x - 1] != '1')
			if (!visited[c.y + 1][c.x - 1])
				enqueue(d, queue, pos(c.x - 1, c.y + 1), p);
	}
	enqueue_all_adjacent_tile2(d, queue, p, visited);
}

void free_visited(t_bool ***visited, t_map* map)
{
	int i;

	i = 0;
	while (i < map->size.y)
	{
		free((*visited)[i]);
		i++;
	}
	free(*visited);
}

int	calculate_path_to_player(t_data *data, t_enemy *enemy)
{
	t_queue	*queue;
	t_bool	**visited;
	t_node	*tmp;
	t_list	*toclear;

	toclear = 0;
	visited = init_visited(data->map);
	queue = 0;
	enqueue(data, &queue, enemy->tile_pos, 0);
	while (queue)
	{
		tmp = dequeue(data, &queue);
		visited[tmp->position.y][tmp->position.x] = TRUE;
		if (is_egal(data->player.tile_pos, tmp->position))
		{
			if (reconstruct_path(tmp, enemy) == -1)
				exit_program(queue, data, toclear, "Malloc error");
			free_queue(&queue, free);
			ft_lstclear(&toclear, free);
			free_visited(&visited, data->map);
			free(tmp);
			return (1);
		}
		enqueue_all_adjacent_tile(data, &queue, tmp, visited);
		add_toclear(data, queue, &toclear, tmp);
	}
	free_visited(&visited, data->map);
	return (no_path_found(&queue, &toclear));
}
