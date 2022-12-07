/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:53:22 by lloison           #+#    #+#             */
/*   Updated: 2022/11/26 15:53:54 by lloison          ###   ########.fr       */
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

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	free_ui(t_data *data)
{
	if (data->ui_images.mouvement_counter)
		mlx_delete_image(data->mlx, data->ui_images.mouvement_counter);
	if (data->ui_images.item_counter)
		mlx_delete_image(data->mlx, data->ui_images.item_counter);
	if (data->ui_images.background)
		mlx_delete_image(data->mlx, data->ui_images.background);
	if (data->ui_images.timer)
		mlx_delete_image(data->mlx, data->ui_images.timer);
	if (data->ui_images.end_text)
		mlx_delete_image(data->mlx, data->ui_images.end_text);
}

void	init_ui(t_data *data)
{
	unsigned long	i;

	i = 0;
	data->ui_images.mouvement_counter = 0;
	data->ui_images.item_counter = 0;
	data->ui_images.timer = 0;
	data->ui_images.background = mlx_new_image(data->mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	if (data->ui_images.background == 0)
		exit_program(data, "Malloc error");
	while (i < WINDOW_WIDTH * WINDOW_HEIGHT * sizeof(int))
	{
		data->ui_images.background->pixels[i] = 0;
		data->ui_images.background->pixels[i + 1] = 0;
		data->ui_images.background->pixels[i + 2] = 0;
		data->ui_images.background->pixels[i + 3] = 220;
		i += 4;
	}
}
