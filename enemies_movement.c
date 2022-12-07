/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:12:52 by lloison           #+#    #+#             */
/*   Updated: 2022/12/07 14:32:21 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_data.h"

static t_bool	has_reached_tile(t_data *data, t_enemy *enemy)
{
	t_pos	target_pos;
	t_pos	enemy_pos;

	target_pos = generate_sprite_pos(data, ((t_pos *)enemy->path->content)->x,
			((t_pos *)enemy->path->content)->y);
	target_pos.x += 32;
	target_pos.y += 32;
	enemy_pos.x = enemy->pixel_pos.x + ENEMY_POS_SHIFT_X;
	enemy_pos.y = enemy->pixel_pos.y + ENEMY_POS_SHIFT_Y;
	if (enemy_pos.x >= target_pos.x - 8
		&& enemy_pos.x <= target_pos.x + 8
		&& enemy_pos.y >= target_pos.y - 8
		&& enemy_pos.y <= target_pos.y + 8)
		return (TRUE);
	return (FALSE);
}

static void	go_to_next_tile(t_enemy *enemy)
{
	t_list	*node;

	node = enemy->path->next;
	free(enemy->path->content);
	free(enemy->path);
	enemy->path = node;
}

static t_pos	get_direction(t_data *data, t_enemy *enemy)
{
	t_pos	target_pos;
	t_pos	direction;

	if (enemy->is_contact || (ft_lstsize(enemy->path) <= 1
			&& enemy->state == chase))
	{
		enemy->is_contact = TRUE;
		target_pos.x = data->player.pixel_pos.x + 16;
		target_pos.y = data->player.pixel_pos.y + 16;
	}
	else
		target_pos = generate_sprite_pos(data,
				((t_pos *)(enemy->path->content))->x,
				((t_pos *)(enemy->path->content))->y);
	direction.x = target_pos.x - enemy->pixel_pos.x;
	direction.y = target_pos.y - enemy->pixel_pos.y;
	return (direction);
}

static int	get_speed_and_update_direction(t_enemy *enemy,
	t_pos direction)
{
	int	speed;

	if (enemy->state == chase)
	{
		speed = ENEMY_CHASE_SPEED;
	}
	else
	{
		speed = ENEMY_PATROL_SPEED;
	}
	if (abs(direction.x) > abs(direction.y))
	{
		if (direction.x > 0)
			enemy->direction = right;
		else
			enemy->direction = left;
	}
	else
	{
		if (direction.y > 0)
			enemy->direction = down;
		else
			enemy->direction = up;
	}
	return (speed);
}

void	move_enemy(t_data *data, t_enemy *enemy)
{
	t_pos	direction;
	double	magnitude;
	int		speed;

	if (enemy->path || enemy->is_contact)
	{
		direction = get_direction(data, enemy);
		speed = get_speed_and_update_direction(enemy, direction);
		magnitude = sqrt(direction.x * direction.x + direction.y * direction.y);
		direction.x = (int)((double)direction.x * 2);
		direction.y = (int)((double)direction.y * 2);
		enemy->pixel_pos.x += (int)(direction.x * speed / 2
				* data->delta_time / magnitude);
		enemy->pixel_pos.y += (int)(direction.y * speed / 2
				* data->delta_time / magnitude);
		if (!enemy->is_contact)
			if (has_reached_tile(data, enemy))
				go_to_next_tile(enemy);
	}
}
