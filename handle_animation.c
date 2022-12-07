/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:44:01 by lloison           #+#    #+#             */
/*   Updated: 2022/11/29 13:21:27 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_data.h"
#include "renderer.h"

static void	items_animation(t_data *data, double time)
{
	static double	last_update;
	int				i;
	int				image_index;

	if (time > last_update + ITEM_ANIMATION_SPEED)
	{
		last_update = time;
		i = -1;
		image_index = data->sprites.item.image_index;
		while (++i < data->map->nb_items)
			data->sprites.item.i[image_index]->enabled = FALSE;
		i = -1;
		image_index++;
		if (image_index >= 6)
			image_index = 0;
		while (++i < data->map->nb_items)
			if (data->sprites.item.collected[i] == FALSE)
				data->sprites.item.i[image_index]->enabled = TRUE;
		data->sprites.item.image_index = image_index;
	}
}

void	handle_animation(t_data *data, double time)
{
	items_animation(data, time);
	player_animation(data, time);
	enemies_animation(data, time);
}
