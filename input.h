/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:53:25 by lloison           #+#    #+#             */
/*   Updated: 2022/11/29 15:22:28 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "t_data.h"

void	check_collision(t_data *data);
void	check_enemy_collision(t_data *data);
void	check_hit_collision(t_data *data);
void	close_game(void *ptr);
void	end_game(t_data *data, t_bool has_won);
void	restart_game(t_data **data);
void	handle_input(void	*ptr);
t_pos	hitbox_corner_to_tile_pos(t_data *data, t_pos pos, t_corner corner);
int		can_move_to(t_data *data, t_direction dir);
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
void	update_player_pos(t_data *data);
void	player_attack(t_data *data);

#endif 