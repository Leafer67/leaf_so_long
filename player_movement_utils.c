/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:18:36 by lloison           #+#    #+#             */
/*   Updated: 2022/11/26 14:31:32 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_data.h"

static void	update_instances_pos(t_data *data, int img_count, ...)
{
	va_list		args;
	int			i;
	mlx_image_t	*tmp;

	va_start(args, img_count);
	i = 0;
	while (i < img_count)
	{
		tmp = va_arg(args, mlx_image_t *);
		tmp->instances[0].x = data->player.pixel_pos.x;
		tmp->instances[0].y = data->player.pixel_pos.y;
		i++;
	}
	va_end(args);
}

void	update_player_pos(t_data *data)
{
	t_char_sprites	*s;

	s = &(data->sprites.player);
	data->player.tile_pos.x = ((data->player.pixel_pos.x + PLAYER_POS_SHIFT_X
				- data->start_pos.x) / SPRITE_WIDTH);
	data->player.tile_pos.y = ((data->player.pixel_pos.y + PLAYER_POS_SHIFT_Y
				- data->start_pos.y) / SPRITE_HEIGHT);
	update_instances_pos(data, 52, s->attack_down[0], s->attack_down[1],
		s->attack_down[2], s->attack_down[3], s->attack_up[0], s->attack_up[1],
		s->attack_up[2], s->attack_up[3], s->attack_left[0], s->attack_left[1],
		s->attack_left[2], s->attack_left[3], s->attack_right[0],
		s->attack_right[1], s->attack_right[2], s->attack_right[3],
		s->walk_down[0], s->walk_down[1], s->walk_down[2], s->walk_down[3],
		s->walk_up[0], s->walk_up[1], s->walk_up[2], s->walk_up[3],
		s->walk_left[0], s->walk_left[1], s->walk_left[2], s->walk_left[3],
		s->walk_right[0], s->walk_right[1], s->walk_right[2], s->walk_right[3],
		s->death[0], s->death[1], s->death[2], s->death[3], s->idle_down[0],
		s->idle_down[1], s->idle_down[2], s->idle_down[3], s->idle_up[0],
		s->idle_up[1], s->idle_up[2], s->idle_up[3], s->idle_left[0],
		s->idle_left[1], s->idle_left[2], s->idle_left[3], s->idle_right[0],
		s->idle_right[1], s->idle_right[2], s->idle_right[3]);
}
