/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_collision_enemy.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:11:03 by lloison           #+#    #+#             */
/*   Updated: 2022/12/07 17:13:18 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_data.h"
#include "input.h"

static t_pos	hitbox_corner_to_pixel_pos(t_data *data, t_corner corner)
{
	t_pos	output;

	output = data->player.pixel_pos;
	if (corner == top_left || corner == top_right)
		output.y += 0;
	else
		output.y += 64;
	if (corner == top_left || corner == bot_left)
		output.x += 0;
	else
		output.x += 64;
	return (output);
}

static t_bool	player_is_hit(t_pos pixel_pos, t_pos corners[])
{
	t_pos	enemy_pos;

	enemy_pos.x = pixel_pos.x + ENEMY_POS_SHIFT_X;
	enemy_pos.y = pixel_pos.y + ENEMY_POS_SHIFT_Y;
	if (enemy_pos.x >= corners[0].x && enemy_pos.y >= corners[0].y
		&& enemy_pos.x <= corners[1].x && enemy_pos.y >= corners[1].y
		&& enemy_pos.x >= corners[2].x && enemy_pos.y <= corners[2].y
		&& enemy_pos.x <= corners[3].x && enemy_pos.y <= corners[3].y)
		return (TRUE);
	return (FALSE);
}

void	check_enemy_collision(t_data *data)
{
	int			i;
	t_pos		hitbox_corners[4];

	i = 0;
	hitbox_corners[0] = hitbox_corner_to_pixel_pos(data, top_left);
	hitbox_corners[1] = hitbox_corner_to_pixel_pos(data, top_right);
	hitbox_corners[2] = hitbox_corner_to_pixel_pos(data, bot_left);
	hitbox_corners[3] = hitbox_corner_to_pixel_pos(data, bot_right);
	while (i < data->enemy_count)
	{
		if (data->enemies[i].is_contact == TRUE
			&& data->enemies[i].state != e_death)
		{
			if (player_is_hit(data->enemies[i].pixel_pos, hitbox_corners))
				end_game(data, FALSE);
		}
		i++;
	}
}
