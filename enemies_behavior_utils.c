/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_behavior_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:14:49 by lloison           #+#    #+#             */
/*   Updated: 2022/11/28 13:46:02 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_data.h"
#include "enemy_behavior.h"

static void	exit_program(t_data *data, char *error_msg)
{
	if (data)
		free_data(&data);
	ft_printf("%s\n", error_msg);
	exit(0);
}

t_bool	has_reached_tile(t_data *data, t_enemy *enemy)
{
	t_pos	target_pos;
	t_pos	tile_pos;

	ft_printf("%p\n", enemy->path->content);
	tile_pos.x = ((t_pos *)(enemy->path->content))->x;
	tile_pos.y = ((t_pos *)(enemy->path->content))->y;
	target_pos = generate_sprite_pos(data, tile_pos.x, tile_pos.y);
	target_pos.x += 32;
	target_pos.y += 32;
	if (enemy->direction == up
		&& enemy->pixel_pos.y + ENEMY_POS_SHIFT_Y <= target_pos.y + 32)
		return (TRUE);
	else if (enemy->direction == down
		&& enemy->pixel_pos.y + ENEMY_POS_SHIFT_Y >= target_pos.y + 32)
		return (TRUE);
	else if (enemy->direction == left
		&& enemy->pixel_pos.x + ENEMY_POS_SHIFT_X <= target_pos.x + 32)
		return (TRUE);
	else if (enemy->direction == right
		&& enemy->pixel_pos.x + ENEMY_POS_SHIFT_X >= target_pos.x + 32)
		return (TRUE);
	return (FALSE);
}

void	add_tile_to_path(t_data *data, t_enemy *enemy, t_pos tile_pos)
{
	t_pos	*content;
	t_list	*node;

	content = malloc(sizeof(t_pos));
	if (content == 0)
		exit_program(data, "Malloc error");
	content->x = tile_pos.x;
	content->y = tile_pos.y;
	node = ft_lstnew(content);
	if (node == 0)
		exit_program(data, "Malloc error");
	ft_lstadd_back(&(enemy->path), node);
}

static t_pos	find_next_patrol_tile2(t_data *data, t_enemy *enemy)
{
	if (enemy->direction == left)
	{
		if (data->map->tiles[enemy->tile_pos.y][enemy->tile_pos.x - 1] == '1')
		{
			if (data->map
				->tiles[enemy->tile_pos.y][enemy->tile_pos.x + 1] == '1')
				return (pos(-1, -1));
			return (pos(enemy->tile_pos.x + 1, enemy->tile_pos.y));
		}
		return (pos(enemy->tile_pos.x - 1, enemy->tile_pos.y));
	}
	else if (enemy->direction == right)
	{
		if (data->map->tiles[enemy->tile_pos.y][enemy->tile_pos.x + 1] == '1')
		{
			if (data->map
				->tiles[enemy->tile_pos.y][enemy->tile_pos.x - 1] == '1')
				return (pos(-1, -1));
			return (pos(enemy->tile_pos.x - 1, enemy->tile_pos.y));
		}
		return (pos(enemy->tile_pos.x + 1, enemy->tile_pos.y));
	}
	return (pos(-1, -1));
}

t_pos	find_next_patrol_tile(t_data *data, t_enemy *enemy)
{
	if (enemy->direction == up)
	{
		if (data->map->tiles[enemy->tile_pos.y - 1][enemy->tile_pos.x] == '1')
		{
			if (data->map
				->tiles[enemy->tile_pos.y + 1][enemy->tile_pos.x] == '1')
				return (pos(-1, -1));
			return (pos(enemy->tile_pos.x, enemy->tile_pos.y + 1));
		}
		return (pos(enemy->tile_pos.x, enemy->tile_pos.y - 1));
	}
	else if (enemy->direction == down)
	{
		if (data->map->tiles[enemy->tile_pos.y + 1][enemy->tile_pos.x] == '1')
		{
			if (data->map
				->tiles[enemy->tile_pos.y - 1][enemy->tile_pos.x] == '1')
				return (pos(-1, -1));
			return (pos(enemy->tile_pos.x, enemy->tile_pos.y - 1));
		}
		return (pos(enemy->tile_pos.x, enemy->tile_pos.y + 1));
	}
	return (find_next_patrol_tile2(data, enemy));
}
