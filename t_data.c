/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_data.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:48:39 by lloison           #+#    #+#             */
/*   Updated: 2022/12/07 18:21:43 by lloison          ###   ########.fr       */
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

static void	init_enemies(t_data *output)
{
	int	i;

	i = 0;
	output->enemies = malloc(sizeof(t_enemy) * output->map->nb_enemies);
	if (output->enemies == 0)
		exit_program(output, "Malloc error");
	while (i < output->map->nb_enemies)
	{
		output->enemies[i].can_move = TRUE;
		output->enemies[i].direction = output->map->enemies_dir[i];
		output->enemies[i].state = patrol;
		output->enemies[i].tile_pos.x = output->map->enemies_pos[i].x;
		output->enemies[i].tile_pos.y = output->map->enemies_pos[i].y;
		output->enemies[i].path = 0;
		output->enemies[i].pixel_pos = generate_sprite_pos(output,
				output->enemies[i].tile_pos.x, output->enemies[i].tile_pos.y);
		output->enemies[i].anim.last_state = patrol;
		output->enemies[i].anim.last_direction = output->enemies[i].direction;
		output->enemies[i].anim.last_update = 0;
		output->enemies[i].anim.sprite_index = 0;
		output->enemies[i].is_contact = FALSE;
		i++;
	}
}

static t_data	*init_data2(t_data *output)
{
	output->sprites.item.collected[1] = FALSE;
	output->sprites.item.collected[2] = FALSE;
	output->sprites.item.collected[3] = FALSE;
	output->sprites.item.collected[4] = FALSE;
	output->sprites.item.collected[5] = FALSE;
	output->game_end = FALSE;
	output->player.action = idle;
	output->player.direction = down;
	output->sprites.player.curr_sprite = output->sprites.player.idle_down[0];
	output->player.pixel_pos = generate_player_sprite_pos(output,
			output->player.tile_pos.x, output->player.tile_pos.y);
	output->timer = 0;
	output->delta_time = 0;
	output->enemy_count = output->map->nb_enemies;
	init_enemies(output);
	output->sprites.enemy.curr_instance = malloc(sizeof(mlx_instance_t *)
			* output->enemy_count);
	if (output->sprites.enemy.curr_instance == 0)
		exit_program(output, "Malloc error");
	output->player.is_attacking = FALSE;
	return (output);
}

t_data	*init_data(mlx_t *mlx, t_map *map)
{
	t_data			*output;

	output = malloc(sizeof(t_data));
	if (output == 0)
		exit_program(0, "Malloc error");
	output->mlx = mlx;
	output->map = map;
	load_all_png(output);
	output->start_pos = pos(
			(WINDOW_WIDTH - map->size.x * SPRITE_WIDTH) / 2 + SPRITE_WIDTH / 2,
			(WINDOW_HEIGHT - map->size.y * SPRITE_HEIGHT)
			/ 2 + SPRITE_HEIGHT / 2);
	output->player.tile_pos.x = output->map->start_pos.x;
	output->player.tile_pos.y = output->map->start_pos.y;
	output->map
		->tiles[output->player.tile_pos.y][output->player.tile_pos.x] = '0';
	output->end_activated = FALSE;
	output->item_collected = 0;
	output->movement_count = 0;
	init_ui(output);
	output->sprites.end->enabled = FALSE;
	output->player.can_move = TRUE;
	output->sprites.item.image_index = 0;
	output->sprites.item.collected[0] = FALSE;
	return (init_data2(output));
}
