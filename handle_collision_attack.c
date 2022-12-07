/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_collision_attack.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:21:30 by lloison           #+#    #+#             */
/*   Updated: 2022/12/07 17:11:14 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_data.h"
#include "enemy_behavior.h"

static void	gen_hitbox_corners2(t_data *data, t_pos hitbox_corners[])
{
	t_pos	p;

	p = pos(data->player.pixel_pos.x + PLAYER_POS_SHIFT_X,
			data->player.pixel_pos.y + PLAYER_POS_SHIFT_Y);
	if (data->player.direction == left)
	{
		hitbox_corners[0] = pos(p.x - 32, p.y - 48);
		hitbox_corners[1] = pos(p.x + 5, p.y - 48);
		hitbox_corners[2] = pos(p.x - 32, p.y + 48);
		hitbox_corners[3] = pos(p.x + 5, p.y + 48);
	}
	else if (data->player.direction == right)
	{
		hitbox_corners[0] = pos(p.x - 5, p.y - 48);
		hitbox_corners[1] = pos(p.x + 32, p.y - 48);
		hitbox_corners[2] = pos(p.x - 5, p.y + 48);
		hitbox_corners[3] = pos(p.x + 32, p.y + 48);
	}
}

static void	gen_hitbox_corners(t_data *data, t_pos hitbox_corners[])
{
	t_pos	p;

	p = pos(data->player.pixel_pos.x + PLAYER_POS_SHIFT_X,
			data->player.pixel_pos.y + PLAYER_POS_SHIFT_Y);
	if (data->player.direction == up)
	{
		hitbox_corners[0] = pos(p.x - 48, p.y - 32);
		hitbox_corners[1] = pos(p.x + 48, p.y - 32);
		hitbox_corners[2] = pos(p.x - 48, p.y + 5);
		hitbox_corners[3] = pos(p.x + 48, p.y + 5);
	}
	else if (data->player.direction == down)
	{
		hitbox_corners[0] = pos(p.x - 48, p.y - 5);
		hitbox_corners[1] = pos(p.x + 48, p.y - 5);
		hitbox_corners[2] = pos(p.x - 48, p.y + 32);
		hitbox_corners[3] = pos(p.x + 48, p.y + 32);
	}
	gen_hitbox_corners2(data, hitbox_corners);
}

static t_bool	enemy_in_hitbox(t_enemy enemy, t_pos hitbox_corners[])
{
	t_pos	enemy_hitbox[4];
	t_pos	p;
	int		i;

	p = pos(enemy.pixel_pos.x, enemy.pixel_pos.y);
	enemy_hitbox[0] = pos(p.x + ENEMY_HITBOX_LEFT, p.y + ENEMY_HITBOX_TOP);
	enemy_hitbox[1] = pos(p.x + ENEMY_HITBOX_RIGHT, p.y + ENEMY_HITBOX_TOP);
	enemy_hitbox[2] = pos(p.x + ENEMY_HITBOX_LEFT, p.y + ENEMY_HITBOX_BOT);
	enemy_hitbox[3] = pos(p.x + ENEMY_HITBOX_RIGHT, p.y + ENEMY_HITBOX_BOT);
	i = 0;
	if (p.x >= hitbox_corners[0].x && p.x <= hitbox_corners[1].x
		&& p.y >= hitbox_corners[0].y && p.y <= hitbox_corners[2].y)
		return (TRUE);
	while (i < 4)
	{
		if (enemy_hitbox[i].x >= hitbox_corners[0].x
			&& enemy_hitbox[i].x <= hitbox_corners[1].x
			&& enemy_hitbox[i].y >= hitbox_corners[0].y
			&& enemy_hitbox[i].y <= hitbox_corners[2].y)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

void	check_hit_collision(t_data *data)
{
	int		i;
	t_pos	hitbox_corners[4];

	i = 0;
	gen_hitbox_corners(data, hitbox_corners);
	while (i < data->enemy_count)
	{
		if (data->enemies[i].state != e_death)
		{
			if (enemy_in_hitbox(data->enemies[i], hitbox_corners))
				kill_enemy(&(data->enemies[i]));
		}
		i++;
	}
}
