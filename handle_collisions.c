/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_collisions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:57:08 by lloison           #+#    #+#             */
/*   Updated: 2022/12/07 15:46:01 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "t_data.h"

static void	collect_item(t_data *data, t_pos p)
{
	data->sprites.item.collected[get_item_index(data,
			data->player.tile_pos)] = TRUE;
	data->item_collected++;
	data->map->tiles[data->player.tile_pos.y][data->player.tile_pos.x] = '0';
	data->sprites.item.i[0]->instances[get_item_index(data, p)].enabled = FALSE;
	data->sprites.item.i[1]->instances[get_item_index(data, p)].enabled = FALSE;
	data->sprites.item.i[2]->instances[get_item_index(data, p)].enabled = FALSE;
	data->sprites.item.i[3]->instances[get_item_index(data, p)].enabled = FALSE;
	data->sprites.item.i[4]->instances[get_item_index(data, p)].enabled = FALSE;
	data->sprites.item.i[5]->instances[get_item_index(data, p)].enabled = FALSE;
	if (data->item_collected == data->map->nb_items)
	{
		data->end_activated = TRUE;
		data->sprites.end->enabled = TRUE;
	}
}

void	check_collision(t_data *data)
{
	if (data->map
		->tiles[data->player.tile_pos.y][data->player.tile_pos.x] == 'C')
		collect_item(data, data->player.tile_pos);
	if (data->map
		->tiles[data->player.tile_pos.y][data->player.tile_pos.x] == 'E'
			&& data->end_activated)
		end_game(data, TRUE);
	check_enemy_collision(data);
	if (data->player.is_attacking)
		check_hit_collision(data);
}
