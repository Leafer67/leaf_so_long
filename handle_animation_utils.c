/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_animation_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:12:18 by lloison           #+#    #+#             */
/*   Updated: 2022/12/07 17:22:42 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_data.h"
#include "renderer.h"

static mlx_image_t	*get_correct_player_sprite2(t_data *data, int index)
{
	if (data->player.action == attack)
	{
		if (index == 3)
		{
			data->player.can_move = TRUE;
			data->player.is_attacking = FALSE;
		}
		if (data->player.direction == up)
			return (data->sprites.player.attack_up[index]);
		else if (data->player.direction == down)
			return (data->sprites.player.attack_down[index]);
		else if (data->player.direction == left)
			return (data->sprites.player.attack_left[index]);
		else
			return (data->sprites.player.attack_right[index]);
	}
	else if (data->player.action == death)
	{
		return (data->sprites.player.death[index]);
	}
	return (0);
}

mlx_image_t	*get_correct_player_sprite(t_data *data, int index)
{
	if (data->player.action == walk)
	{
		if (data->player.direction == up)
			return (data->sprites.player.walk_up[index]);
		else if (data->player.direction == down)
			return (data->sprites.player.walk_down[index]);
		else if (data->player.direction == left)
			return (data->sprites.player.walk_left[index]);
		else
			return (data->sprites.player.walk_right[index]);
	}
	else if (data->player.action == idle)
	{
		if (data->player.direction == up)
			return (data->sprites.player.idle_up[index]);
		else if (data->player.direction == down)
			return (data->sprites.player.idle_down[index]);
		else if (data->player.direction == left)
			return (data->sprites.player.idle_left[index]);
		else
			return (data->sprites.player.idle_right[index]);
	}
	return (get_correct_player_sprite2(data, index));
}

mlx_image_t	*get_correct_enemy_sprite(t_data *data, t_enemy	*e)
{
	int	i;

	i = e->anim.sprite_index;
	if (e->state == patrol || e->state == guard || e->state == stuck)
	{
		if (e->direction == up || e->direction == left)
			return (data->sprites.enemy.walk_left[i]);
		else
			return (data->sprites.enemy.walk_right[i]);
	}
	else if (e->state == chase)
	{
		if (e->direction == up || e->direction == left)
			return (data->sprites.enemy.chase_left[i]);
		else
			return (data->sprites.enemy.chase_right[i]);
	}
	else
	{
		if (e->direction == up || e->direction == left)
			return (data->sprites.enemy.death_left[i]);
		else
			return (data->sprites.enemy.death_right[i]);
	}
}
