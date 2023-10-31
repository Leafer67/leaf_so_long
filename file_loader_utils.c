/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_loader_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:30:18 by lloison           #+#    #+#             */
/*   Updated: 2022/11/28 10:36:11 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_data.h"
#include <stdio.h>

static void	exit_program(t_data *data, char *error_msg)
{
	if (data)
		free_data(&data);
	ft_printf("%s\n", error_msg);
	exit(0);
}

mlx_image_t	*load_png(t_data *data, char *filepath)
{
	mlx_image_t		*output;
	mlx_texture_t	*tmp;

	tmp = mlx_load_png(filepath);
	if (!tmp)
		exit_program(data, ".png files missing or invalid");
	output = mlx_texture_to_image(data->mlx, tmp);
	if (!output)
		exit_program(data, "texture_to_image failed");
	free(tmp);
	return (output);
}
