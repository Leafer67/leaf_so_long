/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_behavior.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:37:57 by lloison           #+#    #+#             */
/*   Updated: 2022/12/07 17:15:02 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_data.h"
#include "enemy_behavior.h"

void	update_enemies(t_data *data, double time)
{
	int	i;

	i = 0;
	while (i < data->enemy_count)
	{
		update_state(data, &(data->enemies[i]));
		if ((data->enemies[i].state == chase
				|| data->enemies[i].state == patrol)
			&& data->enemies[i].can_move)
		{
			if ((!data->enemies[i].path || data->enemies[i].state == chase)
				&& data->enemies[i].is_contact == FALSE)
			{
				update_path(data, &(data->enemies[i]), time,
					!data->enemies[i].path);
			}
			move_enemy(data, &(data->enemies[i]));
		}
		i++;
	}
	update_enemies_pos(data);
}

void	update_state(t_data *data, t_enemy *enemy)
{
	double	distance_to_player;

	if (enemy->state == patrol || enemy->state == guard)
	{
		distance_to_player = sqrt(
				pow(enemy->pixel_pos.x - data->player.pixel_pos.x, 2)
				+ pow(enemy->pixel_pos.y - data->player.pixel_pos.y, 2));
		if (distance_to_player <= DETECTION_DISTANCE)
		{
			enemy->state = chase;
			ft_lstclear(&(enemy->path), free);
		}
	}
	enemy->tile_pos.x = ((enemy->pixel_pos.x + ENEMY_POS_SHIFT_X
				- data->start_pos.x) / SPRITE_WIDTH);
	enemy->tile_pos.y = ((enemy->pixel_pos.y + ENEMY_POS_SHIFT_Y
				- data->start_pos.y) / SPRITE_HEIGHT);
}

void	update_path(t_data *data, t_enemy *enemy,
	double time, t_bool force_update)
{
	t_pos			tmp;
	static double	last_update;

	if (time > last_update + ENEMY_PATH_UPDATE_TIME || force_update)
	{
		last_update = time;
		if (enemy->state == patrol)
		{
			tmp = find_next_patrol_tile(data, enemy);
			if (tmp.x == -1 && tmp.y == -1)
				enemy->state = guard;
			else
				add_tile_to_path(data, enemy, tmp);
		}
		else if (enemy->state == chase)
		{
			ft_lstclear(&(enemy->path), free);
			if (calculate_path_to_player(data, enemy) == -1)
				enemy->state = stuck;
		}
	}
}

void	kill_enemy(t_enemy *enemy)
{
	enemy->state = e_death;
	enemy->can_move = FALSE;
}
