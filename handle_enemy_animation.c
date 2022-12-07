/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_enemy_animation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:29:59 by lloison           #+#    #+#             */
/*   Updated: 2022/12/07 17:10:19 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "t_data.h"

static double	get_anim_speed(t_enemy *enemy)
{
	if (enemy->state == chase)
		return (2);
	return (1);
}

static void	change_current_sprite(t_data *data, int index, t_enemy *e)
{
	mlx_image_t	*tmp;

	tmp = get_correct_enemy_sprite(data, e);
	tmp->instances[index].enabled = TRUE;
	data->sprites.enemy.curr_instance[index]->enabled = FALSE;
	data->sprites.enemy.curr_instance[index] = &(tmp->instances[index]);
}

static void	update_sprites_index(t_enemy *e)
{
	e->anim.sprite_index++;
	if (e->state == e_death)
	{
		if (e->anim.sprite_index == 8)
			e->anim.sprite_index = 7;
	}
	else
	{
		if (e->anim.sprite_index == 6)
			e->anim.sprite_index = 0;
	}
}

void	enemies_animation(t_data *data, double time)
{
	int		i;
	t_enemy	*e;

	i = -1;
	while (++i < data->enemy_count)
	{
		e = &(data->enemies[i]);
		if (e->anim.last_state != e->state
			|| e->anim.last_direction != e->direction)
		{
			e->anim.last_update = time;
			e->anim.last_direction = e->direction;
			e->anim.sprite_index = 0;
			e->anim.last_state = e->state;
			change_current_sprite(data, i, e);
		}
		else if (time > e->anim.last_update
			+ (E_ANIM_SPEED / get_anim_speed(e)))
		{
			e->anim.last_update = time;
			update_sprites_index(e);
			change_current_sprite(data, i, e);
		}
	}
}
