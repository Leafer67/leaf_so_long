/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_movement_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:11:01 by lloison           #+#    #+#             */
/*   Updated: 2022/12/07 15:33:26 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_data.h"

static void	update_instances_pos(t_data *data, int img_count, ...)
{
	va_list		args;
	int			i;
	int			j;
	mlx_image_t	*tmp;

	va_start(args, img_count);
	i = 0;
	while (i < img_count)
	{
		tmp = va_arg(args, mlx_image_t *);
		j = 0;
		while (j < data->enemy_count)
		{
			tmp->instances[j].x = data->enemies[j].pixel_pos.x;
			tmp->instances[j].y = data->enemies[j].pixel_pos.y;
			j++;
		}
		i++;
	}
	va_end(args);
}

static void	update_enemy_pos(t_data *data, t_enemy_sprites *s)
{
	update_instances_pos(data, 40,
		s->chase_left[0], s->chase_left[1], s->chase_left[2],
		s->chase_left[3], s->chase_left[4], s->chase_left[5],
		s->chase_right[0], s->chase_right[1], s->chase_right[2],
		s->chase_right[3], s->chase_right[4], s->chase_right[5],
		s->walk_left[0], s->walk_left[1], s->walk_left[2], s->walk_left[3],
		s->walk_left[4], s->walk_left[5], s->walk_right[0],
		s->walk_right[1], s->walk_right[2], s->walk_right[3],
		s->walk_right[4], s->walk_right[5], s->death_left[0],
		s->death_left[1], s->death_left[2], s->death_left[3],
		s->death_left[4], s->death_left[5], s->death_left[6],
		s->death_left[7], s->death_right[0], s->death_right[1],
		s->death_right[2], s->death_right[3], s->death_right[4],
		s->death_right[5], s->death_right[6], s->death_right[7]);
}

void	update_enemies_pos(t_data *data)
{
	int				i;
	t_enemy_sprites	*s;

	i = 0;
	s = &(data->sprites.enemy);
	while (i < data->enemy_count)
	{
		data->enemies[i].tile_pos.x = ((data->enemies[i].pixel_pos.x
					+ ENEMY_POS_SHIFT_X
					- data->start_pos.x) / SPRITE_WIDTH);
		data->enemies[i].tile_pos.y = ((data->enemies[i].pixel_pos.y
					+ ENEMY_POS_SHIFT_Y
					- data->start_pos.y) / SPRITE_HEIGHT);
		update_enemy_pos(data, s);
		i++;
	}
}
