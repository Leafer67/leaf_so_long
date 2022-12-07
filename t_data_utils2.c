/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_data_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:57:04 by lloison           #+#    #+#             */
/*   Updated: 2022/12/07 13:58:09 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_data.h"

void	free_sprites(t_data *data, int img_count, ...)
{
	va_list		args;
	int			i;
	mlx_image_t	*tmp;

	va_start(args, img_count);
	i = 0;
	while (i < img_count)
	{
		tmp = va_arg(args, mlx_image_t *);
		if (tmp)
			mlx_delete_image(data->mlx, tmp);
		i++;
	}
	va_end(args);
}
