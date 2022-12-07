/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_move_to.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:41:49 by lloison           #+#    #+#             */
/*   Updated: 2022/11/26 16:11:26 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_data.h"
#include "input.h"

static int	get_distance2(t_data *data, t_direction dir, t_pos corners[4])
{
	t_pos	wall_pos;

	if (data->map->tiles[corners[2].y][corners[2].x] == '1')
	{
		wall_pos = generate_sprite_pos(data, corners[2].x, corners[2].y);
		if (dir == down)
			return (wall_pos.y - data->player.pixel_pos.y - PLAYER_HITBOX_BOT
				- (SPRITE_HEIGHT / 2) - 1);
		if (dir == left)
			return (data->player.pixel_pos.x + PLAYER_HITBOX_LEFT
				- SPRITE_WIDTH - wall_pos.x - 1);
	}
	if (data->map->tiles[corners[3].y][corners[3].x] == '1')
	{
		wall_pos = generate_sprite_pos(data, corners[3].x, corners[3].y);
		if (dir == down)
			return (wall_pos.y - data->player.pixel_pos.y - PLAYER_HITBOX_BOT
				- (SPRITE_HEIGHT / 2) - 1 - 1);
		if (dir == right)
			return (wall_pos.x - data->player.pixel_pos.x - PLAYER_HITBOX_RIGHT
				- (SPRITE_WIDTH / 2) - 1 - 1);
	}
	return (PLAYER_SPEED);
}

static int	get_distance(t_data *data, t_direction dir, t_pos corners[4])
{
	t_pos	wall_pos;

	if (data->map->tiles[corners[0].y][corners[0].x] == '1')
	{
		wall_pos = generate_sprite_pos(data, corners[0].x, corners[0].y);
		if (dir == up)
			return (data->player.pixel_pos.y + PLAYER_HITBOX_TOP
				- SPRITE_HEIGHT - wall_pos.y - 1);
		if (dir == left)
			return (data->player.pixel_pos.x + PLAYER_HITBOX_LEFT
				- SPRITE_WIDTH - wall_pos.x - 1);
	}
	if (data->map->tiles[corners[1].y][corners[1].x] == '1')
	{
		wall_pos = generate_sprite_pos(data, corners[1].x, corners[1].y);
		if (dir == up)
			return (data->player.pixel_pos.y + PLAYER_HITBOX_TOP
				- SPRITE_HEIGHT - wall_pos.y - 1);
		if (dir == right)
			return (wall_pos.x - data->player.pixel_pos.x - PLAYER_HITBOX_RIGHT
				- (SPRITE_WIDTH / 2) - 1);
	}
	return (get_distance2(data, dir, corners));
}

int	can_move_to(t_data *data, t_direction dir)
{
	t_pos	desired_pos;
	t_pos	corners[4];
	int		distance;

	desired_pos.y = data->player.pixel_pos.y;
	desired_pos.x = data->player.pixel_pos.x;
	if (dir == up)
		desired_pos.y -= PLAYER_SPEED * data->delta_time;
	else if (dir == down)
		desired_pos.y += PLAYER_SPEED * data->delta_time;
	else if (dir == left)
		desired_pos.x -= PLAYER_SPEED * data->delta_time;
	else if (dir == right)
		desired_pos.x += PLAYER_SPEED * data->delta_time;
	corners[0] = hitbox_corner_to_tile_pos(data, desired_pos, top_left);
	corners[1] = hitbox_corner_to_tile_pos(data, desired_pos, top_right);
	corners[2] = hitbox_corner_to_tile_pos(data, desired_pos, bot_left);
	corners[3] = hitbox_corner_to_tile_pos(data, desired_pos, bot_right);
	distance = get_distance(data, dir, corners);
	if (distance > PLAYER_SPEED * data->delta_time)
		return (PLAYER_SPEED * data->delta_time);
	if (distance > 0)
		return (distance);
	return (0);
}

t_pos	hitbox_corner_to_tile_pos(t_data *data, t_pos pos, t_corner corner)
{
	t_pos	output;

	output.x = pos.x - data->start_pos.x;
	output.y = pos.y - data->start_pos.y;
	if (corner == top_left || corner == top_right)
		output.y += PLAYER_HITBOX_TOP;
	else
		output.y += PLAYER_HITBOX_BOT;
	if (corner == top_left || corner == bot_left)
		output.x += PLAYER_HITBOX_LEFT;
	else
		output.x += PLAYER_HITBOX_RIGHT;
	output.x /= SPRITE_WIDTH;
	output.y /= SPRITE_HEIGHT;
	return (output);
}
