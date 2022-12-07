/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:53:01 by lloison           #+#    #+#             */
/*   Updated: 2022/12/07 14:22:01 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "renderer.h"
#include "enemy_behavior.h"

static void	check_player_input(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_SPACE))
		player_attack(data);
	else if (data->player.can_move)
	{
		if (mlx_is_key_down(data->mlx, MLX_KEY_A))
			move_left(data);
		else if (mlx_is_key_down(data->mlx, MLX_KEY_D))
			move_right(data);
		if (mlx_is_key_down(data->mlx, MLX_KEY_S))
			move_down(data);
		else if (mlx_is_key_down(data->mlx, MLX_KEY_W))
			move_up(data);
		if (!mlx_is_key_down(data->mlx, MLX_KEY_A)
			&& !mlx_is_key_down(data->mlx, MLX_KEY_D)
			&& !mlx_is_key_down(data->mlx, MLX_KEY_S)
			&& !mlx_is_key_down(data->mlx, MLX_KEY_W))
			data->player.action = idle;
		else
			ft_printf("Movement count : %d.%02dm\n", data->movement_count / 100,
				data->movement_count % 100);
	}
}

static double	update_time(t_data *data)
{
	static double	last_update;
	double			time;

	if (last_update == 0)
	{
		last_update = mlx_get_time();
		time = last_update;
	}
	else
	{
		time = mlx_get_time();
		data->delta_time = time - last_update;
		last_update = time;
	}
	return (time);
}

void	handle_input(void *ptr)
{
	t_data			**data;
	double			time;

	data = (t_data **)ptr;
	time = update_time(*data);
	if (!(*data)->game_end)
	{
		update_enemies(*data, time);
		check_player_input(*data);
		check_collision(*data);
		update_ui(*data, FALSE, time);
		handle_animation(*data, time);
	}
	else if (mlx_is_key_down((*data)->mlx, MLX_KEY_R))
		restart_game(data);
	if (mlx_is_key_down((*data)->mlx, MLX_KEY_ESCAPE))
		close_game(*data);
}
