/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:43:18 by lloison           #+#    #+#             */
/*   Updated: 2022/11/27 11:16:52 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_data.h"
#include "input.h"
#include "renderer.h"

void	move_right(t_data *data)
{
	int	distance;

	distance = can_move_to(data, right);
	if (distance > 0)
	{
		if (data->player.action != walk)
			data->player.action = walk;
		if (data->player.direction != right)
			data->player.direction = right;
		data->movement_count += distance;
		data->player.pixel_pos.x += distance;
		update_player_pos(data);
	}
}

void	move_up(t_data *data)
{
	int	distance;

	distance = can_move_to(data, up);
	if (distance > 0)
	{
		if (data->player.action != walk)
			data->player.action = walk;
		if (data->player.direction != up)
			data->player.direction = up;
		data->movement_count += distance;
		data->player.pixel_pos.y -= distance;
		update_player_pos(data);
	}
}

void	move_down(t_data *data)
{
	int	distance;

	distance = can_move_to(data, down);
	if (distance > 0)
	{
		if (data->player.action != walk)
			data->player.action = walk;
		if (data->player.direction != down)
			data->player.direction = down;
		data->movement_count += distance;
		data->player.pixel_pos.y += distance;
		update_player_pos(data);
	}
}

void	move_left(t_data *data)
{
	int	distance;

	distance = can_move_to(data, left);
	if (distance > 0)
	{
		if (data->player.action != walk)
			data->player.action = walk;
		if (data->player.direction != left)
			data->player.direction = left;
		data->movement_count += distance;
		data->player.pixel_pos.x -= distance;
		update_player_pos(data);
	}
}
