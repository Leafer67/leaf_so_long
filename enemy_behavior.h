/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_behavior.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:15:51 by lloison           #+#    #+#             */
/*   Updated: 2022/12/07 17:10:50 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_BEHAVIOR_H
# define ENEMY_BEHAVIOR_H

# include "t_data.h"
# include "queue.h"

void	update_enemies(t_data *data, double time);
void	update_state(t_data *data, t_enemy *enemy);
void	update_enemies_pos(t_data *data);
void	update_path(t_data *data, t_enemy *enemy,
			double time, t_bool force_update);
void	move_enemy(t_data *data, t_enemy *enemy);
t_bool	has_reached_tile(t_data *data, t_enemy *enemy);
void	add_tile_to_path(t_data *data, t_enemy *enemy, t_pos tile_pos);
t_pos	find_next_patrol_tile(t_data *data, t_enemy *enemy);
int		calculate_path_to_player(t_data *data, t_enemy *enemy);
void	add_toclear(t_data *data, t_queue *queue,
			t_list **toclear, t_node *to_add);
int		reconstruct_path(t_node *end_node, t_enemy *enemy);
int		no_path_found(t_queue **queue, t_list **toclear);
void	kill_enemy(t_enemy *enemy);

#endif