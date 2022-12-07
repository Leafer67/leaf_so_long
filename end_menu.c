/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_menu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:23:12 by lloison           #+#    #+#             */
/*   Updated: 2022/11/26 15:53:23 by lloison          ###   ########.fr       */
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

void	display_end_menu(t_data *data, t_bool won)
{
	if (mlx_image_to_window(data->mlx, data->ui_images.background, 0, 0) < 0)
		exit_program(data, "mlx_image_to_window failed");
	update_ui(data, TRUE, 0);
	mlx_set_instance_depth(&(data->ui_images.background->instances[0]),
		(data->map->size.x + 1) * (data->map->size.y + 1));
	if (won)
	{
		data->ui_images.end_text = mlx_put_string(data->mlx, "YOU WON !",
				WINDOW_WIDTH / 2 - 50,
				WINDOW_HEIGHT / 2 - 5);
		if (data->ui_images.end_text < 0)
			exit_program(data, "mlx_put_string failed");
	}
	else
	{
		data->ui_images.end_text = mlx_put_string(data->mlx, "YOU LOSE !",
				WINDOW_WIDTH / 2 - 50,
				WINDOW_HEIGHT / 2 - 5);
		if (data->ui_images.end_text < 0)
			exit_program(data, "mlx_put_string failed");
	}
}
