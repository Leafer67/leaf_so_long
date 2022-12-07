/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:52:56 by lloison           #+#    #+#             */
/*   Updated: 2022/11/26 16:15:05 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_data.h"
#include "renderer.h"

static void	exit_program(t_data *data, char *error_msg)
{
	free_data(&data);
	ft_printf("%s\n", error_msg);
	exit(0);
}

void	update_ui(t_data *data, t_bool force_update, double time)
{
	static double	last_update;

	if (time > last_update + UI_REFRESH_TIME || force_update)
	{
		data->timer += time - last_update;
		last_update = time;
		update_texts(data);
		update_timer(data);
	}
}

void	update_timer(t_data *data)
{
	char		*tmp_s;
	mlx_image_t	*tmp_i;

	tmp_s = generate_fstring("Time : %d.%ds", (int)(data->timer),
			((int)(data->timer * (double)1000) % 1000));
	tmp_i = data->ui_images.timer;
	data->ui_images.timer = mlx_put_string(data->mlx, tmp_s, 0, 50);
	mlx_delete_image(data->mlx, tmp_i);
	if (!data->ui_images.timer)
		exit_program(data, "Failed mlx_put_string");
	mlx_set_instance_depth(&(data->ui_images.timer->instances[0]),
		(data->map->size.x + 1) * (data->map->size.y + 1) + 2);
	free(tmp_s);
}

void	update_texts(t_data *data)
{
	char		*tmp_s1;
	char		*tmp_s2;
	mlx_image_t	*tmp_i1;
	mlx_image_t	*tmp_i2;

	tmp_s1 = generate_fstring("Movement count : %d.%dm",
			data->movement_count / 100, data->movement_count % 100);
	tmp_s2 = generate_fstring("Item count : %d / %d", data->item_collected,
			data->map->nb_items);
	tmp_i1 = data->ui_images.mouvement_counter;
	tmp_i2 = data->ui_images.item_counter;
	data->ui_images.mouvement_counter = mlx_put_string(data->mlx, tmp_s1,
			0, 10);
	data->ui_images.item_counter = mlx_put_string(data->mlx, tmp_s2, 0, 30);
	mlx_delete_image(data->mlx, tmp_i1);
	mlx_delete_image(data->mlx, tmp_i2);
	if (!data->ui_images.mouvement_counter || !data->ui_images.item_counter)
		exit_program(data, "Failed mlx_put_string");
	mlx_set_instance_depth(&(data->ui_images.item_counter->instances[0]),
		(data->map->size.x + 1) * (data->map->size.y + 1) + 1);
	free(tmp_s1);
	free(tmp_s2);
}
