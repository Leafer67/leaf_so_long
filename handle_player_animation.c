/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player_animation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:26:33 by lloison           #+#    #+#             */
/*   Updated: 2022/11/29 13:09:14 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_data.h"
#include "renderer.h"

static void	change_current_sprite(t_data *data, int index)
{
	mlx_image_t	*tmp;

	tmp = get_correct_player_sprite(data, index);
	tmp->enabled = TRUE;
	data->sprites.player.curr_sprite->enabled = FALSE;
	data->sprites.player.curr_sprite = tmp;
}

static double	get_anim_speed(t_data *data)
{
	if (data->player.action == attack)
		return (2.5);
	return (1);
}

void	player_animation(t_data *data, double time)
{
	static t_player_action	last_action;
	static t_direction		last_direction;
	static double			last_update;
	static int				index;
	double					anim_speed;

	anim_speed = get_anim_speed(data);
	if (last_action != data->player.action
		|| last_direction != data->player.direction)
	{
		last_update = time;
		last_action = data->player.action;
		last_direction = data->player.direction;
		index = 0;
		change_current_sprite(data, index);
	}
	else if (time > last_update + (PLAYER_ANIMATION_SPEED / anim_speed))
	{
		last_update = time;
		index++;
		if (index == 4)
			index = 0;
		change_current_sprite(data, index);
	}
}
