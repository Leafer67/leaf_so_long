/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:27:16 by lloison           #+#    #+#             */
/*   Updated: 2022/12/07 18:07:37 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "libft/libft_e.h"
# include "defines.h"

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_map
{
	t_pos		size;
	char		**tiles;
	int			nb_items;
	int			nb_enemies;
	t_pos		*items_pos;
	t_pos		*enemies_pos;
	t_direction	*enemies_dir;
	t_pos		exit_pos;
	t_pos		start_pos;
}	t_map;

void	free_map(t_map *map);

#endif