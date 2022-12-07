/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:17:31 by lloison           #+#    #+#             */
/*   Updated: 2022/11/28 12:03:26 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

static void	exit_program(t_data *data, char *error_msg)
{
	if (data)
		free_data(&data);
	ft_printf("%s\n", error_msg);
	exit(0);
}

void	disabled_images_to_pos(t_data *data, t_pos pos, int img_count, ...)
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
		tmp->enabled = FALSE;
		i++;
	}
	va_end(args);
}

void	render_frame(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map->size.y)
	{
		j = 0;
		while (j < data->map->size.x)
		{
			put_correct_sprite(data, generate_sprite_pos(data, j, i), j, i);
			j++;
		}
		i++;
	}
	put_player_sprites(data);
	put_enemies_sprites(data);
	update_ui(data, TRUE, 0);
}

static void	put_item_sprites(t_data *data, t_pos pos)
{
	pos.x += SPRITE_WIDTH / 4;
	pos.y += SPRITE_HEIGHT / 4;
	disabled_images_to_pos(data, pos, 6, data->sprites.item.i[0],
		data->sprites.item.i[1], data->sprites.item.i[2],
		data->sprites.item.i[3], data->sprites.item.i[4],
		data->sprites.item.i[5]);
	data->sprites.item.i[0]->enabled = TRUE;
}

void	put_correct_sprite(t_data *data, t_pos pos, int x, int y)
{
	if (data->map->tiles[y][x] == '1')
	{
		if (mlx_image_to_window(data->mlx, data->sprites.wall,
				pos.x, pos.y) < 0)
			exit_program(data, "mlx_image_to_window failed");
	}
	else if (data->map->tiles[y][x] == '0')
	{
		if (mlx_image_to_window(data->mlx, data->sprites.ground,
				pos.x, pos.y) < 0)
			exit_program(data, "mlx_image_to_window failed");
	}
	else
	{
		if (mlx_image_to_window(data->mlx, data->sprites.ground,
				pos.x, pos.y) < 0)
			exit_program(data, "mlx_image_to_window failed");
		if (data->map->tiles[y][x] == 'C')
			put_item_sprites(data, pos);
		else if (data->map->tiles[y][x] == 'E')
			if (mlx_image_to_window(data->mlx, data->sprites.end,
					pos.x, pos.y) < 0)
				exit_program(data, "mlx_image_to_window failed");
	}
}
