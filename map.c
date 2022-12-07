/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:51:42 by lloison           #+#    #+#             */
/*   Updated: 2022/11/21 10:45:30 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	free_map(t_map **map)
{
	int	i;

	i = 0;
	if (*map)
	{
		if ((*map)->tiles)
		{
			while ((*map)->tiles[i] && i < (*map)->size.y)
			{
				free((*map)->tiles[i]);
				i++;
			}
			free((*map)->tiles);
		}
		if ((*map)->items_pos)
			free((*map)->items_pos);
	}
	free(*map);
}
