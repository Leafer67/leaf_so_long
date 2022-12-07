/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_characters_sprites.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:01:59 by lloison           #+#    #+#             */
/*   Updated: 2022/11/29 13:57:24 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_data.h"
#include "renderer.h"

static void	exit_program(t_data *data, char *error_msg)
{
	if (data)
		free_data(&data);
	ft_printf("%s\n", error_msg);
	exit(0);
}

void	enabled_images_to_pos(t_data *data, t_pos pos, int img_count, ...)
{
	va_list		args;
	int			i;
	mlx_image_t	*tmp;

	va_start(args, img_count);
	i = 0;
	while (i < img_count)
	{
		tmp = va_arg(args, mlx_image_t *);
		if (mlx_image_to_window(data->mlx, tmp,
				pos.x, pos.y) < 0)
			exit_program(data, "mlx_image_to_window failed");
		i++;
	}
	va_end(args);
}

void	put_player_sprites(t_data *data)
{
	t_pos			pos;
	t_char_sprites	*s;

	pos = generate_player_sprite_pos(data, data->player.tile_pos.x,
			data->player.tile_pos.y);
	s = &(data->sprites.player);
	disabled_images_to_pos(data, pos, 52, s->attack_down[0], s->attack_down[1],
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
	data->sprites.player.idle_down[0]->enabled = TRUE;
}

static void	put_enemy_sprites(t_data *data, t_pos pos)
{
	t_enemy_sprites	*s;

	s = &(data->sprites.enemy);
	enabled_images_to_pos(data, pos, 40,
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

void	put_enemies_sprites(t_data *data)
{
	int				i;

	i = 0;
	while (i < data->enemy_count)
	{
		put_enemy_sprites(data, data->enemies[i].pixel_pos);
		disable_all_instances(data, i);
		if (data->enemies[i].direction == up
			|| data->enemies[i].direction == left)
		{
			data->sprites.enemy.walk_left[0]->instances[i].enabled = true;
			data->sprites.enemy.curr_instance[i] = &(data
					->sprites.enemy.walk_left[0]->instances[i]);
		}
		else
		{
			data->sprites.enemy.walk_right[0]->instances[i].enabled = true;
			data->sprites.enemy.curr_instance[i] = &(data
					->sprites.enemy.walk_right[0]->instances[i]);
		}
		i++;
	}
}
