/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:40:31 by lloison           #+#    #+#             */
/*   Updated: 2022/12/07 14:20:16 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "t_data.h"

t_pos	pos(int x, int y)
{
	t_pos	output;

	output.x = x;
	output.y = y;
	return (output);
}

t_pos	generate_sprite_pos(t_data *data, int x, int y)
{
	t_pos	output;

	output.x = data->start_pos.x + SPRITE_WIDTH * x;
	output.y = data->start_pos.y + SPRITE_HEIGHT * y;
	output.x -= (x >= (data->map->size.x + 1) / 2);
	output.y -= (y >= (data->map->size.y + 1) / 2);
	return (output);
}

t_pos	generate_player_sprite_pos(t_data *data, int x, int y)
{
	t_pos	output;

	output.x = data->start_pos.x + SPRITE_WIDTH * x - 16;
	output.y = data->start_pos.y + SPRITE_HEIGHT * y - 16;
	output.x -= (x >= (data->map->size.x + 1) / 2);
	output.y -= (y >= (data->map->size.y + 1) / 2);
	return (output);
}

t_bool	is_egal(t_pos pos1, t_pos pos2)
{
	if (pos1.x == pos2.x && pos1.y == pos2.y)
		return (TRUE);
	return (FALSE);
}
