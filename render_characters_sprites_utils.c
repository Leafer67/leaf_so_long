/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_characters_sprites_utils.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:23:31 by lloison           #+#    #+#             */
/*   Updated: 2022/11/28 12:50:50 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_data.h"
#include "renderer.h"

static void	disable_instances(int instances_count, ...)
{
	va_list			args;
	int				i;
	mlx_instance_t	*tmp;

	va_start(args, instances_count);
	i = 0;
	while (i < instances_count)
	{
		tmp = va_arg(args, mlx_instance_t *);
		tmp->enabled = false;
		i++;
	}
	va_end(args);
}

void	disable_all_instances(t_data *data, int i)
{
	t_enemy_sprites	*s;

	s = &(data->sprites.enemy);
	disable_instances(40,
		&(s->chase_left[0]->instances[i]), &(s->chase_left[1]->instances[i]),
		&(s->chase_left[2]->instances[i]), &(s->chase_left[3]->instances[i]),
		&(s->chase_left[4]->instances[i]), &(s->chase_left[5]->instances[i]),
		&(s->chase_right[0]->instances[i]), &(s->chase_right[1]->instances[i]),
		&(s->chase_right[2]->instances[i]), &(s->chase_right[3]->instances[i]),
		&(s->chase_right[4]->instances[i]), &(s->chase_right[5]->instances[i]),
		&(s->walk_left[0]->instances[i]), &(s->walk_left[1]->instances[i]),
		&(s->walk_left[2]->instances[i]), &(s->walk_left[3]->instances[i]),
		&(s->walk_left[4]->instances[i]), &(s->walk_left[5]->instances[i]),
		&(s->walk_right[0]->instances[i]), &(s->walk_right[1]->instances[i]),
		&(s->walk_right[2]->instances[i]), &(s->walk_right[3]->instances[i]),
		&(s->walk_right[4]->instances[i]), &(s->walk_right[5]->instances[i]),
		&(s->death_left[0]->instances[i]), &(s->death_left[1]->instances[i]),
		&(s->death_left[2]->instances[i]), &(s->death_left[3]->instances[i]),
		&(s->death_left[4]->instances[i]), &(s->death_left[5]->instances[i]),
		&(s->death_left[6]->instances[i]), &(s->death_left[7]->instances[i]),
		&(s->death_right[0]->instances[i]), &(s->death_right[1]->instances[i]),
		&(s->death_right[2]->instances[i]), &(s->death_right[3]->instances[i]),
		&(s->death_right[4]->instances[i]), &(s->death_right[5]->instances[i]),
		&(s->death_right[6]->instances[i]), &(s->death_right[7]->instances[i]));
}
