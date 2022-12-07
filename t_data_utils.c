/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_data_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:48:40 by lloison           #+#    #+#             */
/*   Updated: 2022/12/07 18:15:18 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_data.h"

static void	free_enemy_sprites(t_data *data)
{
	t_enemy_sprites	*s;

	s = &(data->sprites.enemy);
	free_sprites(data, 40, s->chase_left[0], s->chase_left[1],
		s->chase_left[2], s->chase_left[3], s->chase_left[4],
		s->chase_left[5], s->chase_right[0], s->chase_right[1],
		s->chase_right[2], s->chase_right[3], s->chase_right[4],
		s->chase_right[5], s->walk_left[0], s->walk_left[1], s->walk_left[2],
		s->walk_left[3], s->walk_left[4], s->walk_left[5], s->walk_right[0],
		s->walk_right[1], s->walk_right[2], s->walk_right[3], s->walk_right[4],
		s->walk_right[5], s->death_left[0], s->death_left[1], s->death_left[2],
		s->death_left[3], s->death_left[4], s->death_left[5], s->death_left[6],
		s->death_left[7], s->death_right[0], s->death_right[1],
		s->death_right[2], s->death_right[3], s->death_right[4],
		s->death_right[5], s->death_right[6], s->death_right[7]);
}

static void	free_all_sprites(t_data *data)
{
	t_sprites		*s;
	t_char_sprites	*c;

	s = &(data->sprites);
	c = &(s->player);
	free_sprites(data, 61, s->wall, s->end, s->ground, s->item.i[0],
		s->item.i[1], s->item.i[2], s->item.i[3], s->item.i[4],
		s->item.i[5], c->attack_down[0], c->attack_down[1],
		c->attack_down[2], c->attack_down[3], c->attack_up[0],
		c->attack_up[1], c->attack_up[2], c->attack_up[3],
		c->attack_left[0], c->attack_left[1], c->attack_left[2],
		c->attack_left[3], c->attack_right[0], c->attack_right[1],
		c->attack_right[2], c->attack_right[3], c->walk_down[0],
		c->walk_down[1], c->walk_down[2], c->walk_down[3],
		c->walk_up[0], c->walk_up[1], c->walk_up[2], c->walk_up[3],
		c->walk_left[0], c->walk_left[1], c->walk_left[2], c->walk_left[3],
		c->walk_right[0], c->walk_right[1], c->walk_right[2],
		c->walk_right[3], c->death[0], c->death[1], c->death[2],
		c->death[3], c->idle_down[0], c->idle_down[1], c->idle_down[2],
		c->idle_down[3], c->idle_up[0], c->idle_up[1], c->idle_up[2],
		c->idle_up[3], c->idle_left[0], c->idle_left[1], c->idle_left[2],
		c->idle_left[3], c->idle_right[0], c->idle_right[1],
		c->idle_right[2], c->idle_right[3]);
	free_enemy_sprites(data);
}

static void	free_enemies_path(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->enemy_count)
	{
		ft_lstclear(&(data->enemies[i].path), free);
		i++;
	}
}

void	free_data(t_data **data)
{
	if ((*data))
	{
		free_all_sprites(*data);
		free_ui(*data);
		free_enemies_path(*data);
		mlx_terminate((*data)->mlx);
		free((*data));
		exit(0);
	}
}

void	reset_data(t_data *data)
{
	if (data)
	{
		free_all_sprites(data);
		free_ui(data);
		free_enemies_path(data);
		free(data);
	}
}
