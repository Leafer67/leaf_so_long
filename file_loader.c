/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_loader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:33:32 by lloison           #+#    #+#             */
/*   Updated: 2022/11/28 10:36:18 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_data.h"

static void	load_all_png5(t_data *data)
{
	data->sprites.enemy.death_right[2] = load_png(data, SPRITE_E_DEATH_RIGHT3);
	data->sprites.enemy.death_right[3] = load_png(data, SPRITE_E_DEATH_RIGHT4);
	data->sprites.enemy.death_right[4] = load_png(data, SPRITE_E_DEATH_RIGHT5);
	data->sprites.enemy.death_right[5] = load_png(data, SPRITE_E_DEATH_RIGHT6);
	data->sprites.enemy.death_right[6] = load_png(data, SPRITE_E_DEATH_RIGHT7);
	data->sprites.enemy.death_right[7] = load_png(data, SPRITE_E_DEATH_RIGHT8);
}

static void	load_all_png4(t_data *data)
{
	data->sprites.enemy.walk_right[5] = load_png(data, SPRITE_E_WALK_RIGHT6);
	data->sprites.enemy.chase_left[0] = load_png(data, SPRITE_E_CHASE_LEFT1);
	data->sprites.enemy.chase_left[1] = load_png(data, SPRITE_E_CHASE_LEFT2);
	data->sprites.enemy.chase_left[2] = load_png(data, SPRITE_E_CHASE_LEFT3);
	data->sprites.enemy.chase_left[3] = load_png(data, SPRITE_E_CHASE_LEFT4);
	data->sprites.enemy.chase_left[4] = load_png(data, SPRITE_E_CHASE_LEFT5);
	data->sprites.enemy.chase_left[5] = load_png(data, SPRITE_E_CHASE_LEFT6);
	data->sprites.enemy.chase_right[0] = load_png(data, SPRITE_E_CHASE_RIGHT1);
	data->sprites.enemy.chase_right[1] = load_png(data, SPRITE_E_CHASE_RIGHT2);
	data->sprites.enemy.chase_right[2] = load_png(data, SPRITE_E_CHASE_RIGHT3);
	data->sprites.enemy.chase_right[3] = load_png(data, SPRITE_E_CHASE_RIGHT4);
	data->sprites.enemy.chase_right[4] = load_png(data, SPRITE_E_CHASE_RIGHT5);
	data->sprites.enemy.chase_right[5] = load_png(data, SPRITE_E_CHASE_RIGHT6);
	data->sprites.enemy.death_left[0] = load_png(data, SPRITE_E_DEATH_LEFT1);
	data->sprites.enemy.death_left[1] = load_png(data, SPRITE_E_DEATH_LEFT2);
	data->sprites.enemy.death_left[2] = load_png(data, SPRITE_E_DEATH_LEFT3);
	data->sprites.enemy.death_left[3] = load_png(data, SPRITE_E_DEATH_LEFT4);
	data->sprites.enemy.death_left[4] = load_png(data, SPRITE_E_DEATH_LEFT5);
	data->sprites.enemy.death_left[5] = load_png(data, SPRITE_E_DEATH_LEFT6);
	data->sprites.enemy.death_left[6] = load_png(data, SPRITE_E_DEATH_LEFT7);
	data->sprites.enemy.death_left[7] = load_png(data, SPRITE_E_DEATH_LEFT8);
	data->sprites.enemy.death_right[0] = load_png(data, SPRITE_E_DEATH_RIGHT1);
	data->sprites.enemy.death_right[1] = load_png(data, SPRITE_E_DEATH_RIGHT2);
	data->sprites.enemy.death_right[2] = load_png(data, SPRITE_E_DEATH_RIGHT3);
	load_all_png5(data);
}

static void	load_all_png3(t_data *data)
{
	data->sprites.player.idle_up[3] = load_png(data, SPRITE_P_IDLE_UP4);
	data->sprites.player.idle_left[0] = load_png(data, SPRITE_P_IDLE_LEFT1);
	data->sprites.player.idle_left[1] = load_png(data, SPRITE_P_IDLE_LEFT2);
	data->sprites.player.idle_left[2] = load_png(data, SPRITE_P_IDLE_LEFT3);
	data->sprites.player.idle_left[3] = load_png(data, SPRITE_P_IDLE_LEFT4);
	data->sprites.player.idle_right[0] = load_png(data, SPRITE_P_IDLE_RIGHT1);
	data->sprites.player.idle_right[1] = load_png(data, SPRITE_P_IDLE_RIGHT2);
	data->sprites.player.idle_right[2] = load_png(data, SPRITE_P_IDLE_RIGHT3);
	data->sprites.player.idle_right[3] = load_png(data, SPRITE_P_IDLE_RIGHT4);
	data->sprites.player.death[0] = load_png(data, SPRITE_P_DEATH1);
	data->sprites.player.death[1] = load_png(data, SPRITE_P_DEATH2);
	data->sprites.player.death[2] = load_png(data, SPRITE_P_DEATH3);
	data->sprites.player.death[3] = load_png(data, SPRITE_P_DEATH4);
	data->sprites.enemy.walk_left[0] = load_png(data, SPRITE_E_WALK_LEFT1);
	data->sprites.enemy.walk_left[1] = load_png(data, SPRITE_E_WALK_LEFT2);
	data->sprites.enemy.walk_left[2] = load_png(data, SPRITE_E_WALK_LEFT3);
	data->sprites.enemy.walk_left[3] = load_png(data, SPRITE_E_WALK_LEFT4);
	data->sprites.enemy.walk_left[4] = load_png(data, SPRITE_E_WALK_LEFT5);
	data->sprites.enemy.walk_left[5] = load_png(data, SPRITE_E_WALK_LEFT6);
	data->sprites.enemy.walk_right[0] = load_png(data, SPRITE_E_WALK_RIGHT1);
	data->sprites.enemy.walk_right[1] = load_png(data, SPRITE_E_WALK_RIGHT2);
	data->sprites.enemy.walk_right[2] = load_png(data, SPRITE_E_WALK_RIGHT3);
	data->sprites.enemy.walk_right[3] = load_png(data, SPRITE_E_WALK_RIGHT4);
	data->sprites.enemy.walk_right[4] = load_png(data, SPRITE_E_WALK_RIGHT5);
	load_all_png4(data);
}

static void	load_all_png2(t_data *data)
{
	data->sprites.player.attack_right[3] = load_png(data, SPRITE_P_ATAK_RIGHT4);
	data->sprites.player.walk_down[0] = load_png(data, SPRITE_P_WALK_DOWN1);
	data->sprites.player.walk_down[1] = load_png(data, SPRITE_P_WALK_DOWN2);
	data->sprites.player.walk_down[2] = load_png(data, SPRITE_P_WALK_DOWN3);
	data->sprites.player.walk_down[3] = load_png(data, SPRITE_P_WALK_DOWN4);
	data->sprites.player.walk_up[0] = load_png(data, SPRITE_P_WALK_UP1);
	data->sprites.player.walk_up[1] = load_png(data, SPRITE_P_WALK_UP2);
	data->sprites.player.walk_up[2] = load_png(data, SPRITE_P_WALK_UP3);
	data->sprites.player.walk_up[3] = load_png(data, SPRITE_P_WALK_UP4);
	data->sprites.player.walk_left[0] = load_png(data, SPRITE_P_WALK_LEFT1);
	data->sprites.player.walk_left[1] = load_png(data, SPRITE_P_WALK_LEFT2);
	data->sprites.player.walk_left[2] = load_png(data, SPRITE_P_WALK_LEFT3);
	data->sprites.player.walk_left[3] = load_png(data, SPRITE_P_WALK_LEFT4);
	data->sprites.player.walk_right[0] = load_png(data, SPRITE_P_WALK_RIGHT1);
	data->sprites.player.walk_right[1] = load_png(data, SPRITE_P_WALK_RIGHT2);
	data->sprites.player.walk_right[2] = load_png(data, SPRITE_P_WALK_RIGHT3);
	data->sprites.player.walk_right[3] = load_png(data, SPRITE_P_WALK_RIGHT4);
	data->sprites.player.idle_down[0] = load_png(data, SPRITE_P_IDLE_DOWN1);
	data->sprites.player.idle_down[1] = load_png(data, SPRITE_P_IDLE_DOWN2);
	data->sprites.player.idle_down[2] = load_png(data, SPRITE_P_IDLE_DOWN3);
	data->sprites.player.idle_down[3] = load_png(data, SPRITE_P_IDLE_DOWN4);
	data->sprites.player.idle_up[0] = load_png(data, SPRITE_P_IDLE_UP1);
	data->sprites.player.idle_up[1] = load_png(data, SPRITE_P_IDLE_UP2);
	data->sprites.player.idle_up[2] = load_png(data, SPRITE_P_IDLE_UP3);
	load_all_png3(data);
}

void	load_all_png(t_data *data)
{
	data->sprites.end = load_png(data, SPRITE_END_FILE);
	data->sprites.wall = load_png(data, SPRITE_WALL_FILE);
	data->sprites.ground = load_png(data, SPRITE_GROUND_FILE);
	data->sprites.item.i[0] = load_png(data, SPRITE_ITEM01_FILE);
	data->sprites.item.i[1] = load_png(data, SPRITE_ITEM02_FILE);
	data->sprites.item.i[2] = load_png(data, SPRITE_ITEM03_FILE);
	data->sprites.item.i[3] = load_png(data, SPRITE_ITEM04_FILE);
	data->sprites.item.i[4] = load_png(data, SPRITE_ITEM05_FILE);
	data->sprites.item.i[5] = load_png(data, SPRITE_ITEM06_FILE);
	data->sprites.player.attack_down[0] = load_png(data, SPRITE_P_ATAK_DOWN1);
	data->sprites.player.attack_down[1] = load_png(data, SPRITE_P_ATAK_DOWN2);
	data->sprites.player.attack_down[2] = load_png(data, SPRITE_P_ATAK_DOWN3);
	data->sprites.player.attack_down[3] = load_png(data, SPRITE_P_ATAK_DOWN4);
	data->sprites.player.attack_up[0] = load_png(data, SPRITE_P_ATAK_UP1);
	data->sprites.player.attack_up[1] = load_png(data, SPRITE_P_ATAK_UP2);
	data->sprites.player.attack_up[2] = load_png(data, SPRITE_P_ATAK_UP3);
	data->sprites.player.attack_up[3] = load_png(data, SPRITE_P_ATAK_UP4);
	data->sprites.player.attack_left[0] = load_png(data, SPRITE_P_ATAK_LEFT1);
	data->sprites.player.attack_left[1] = load_png(data, SPRITE_P_ATAK_LEFT2);
	data->sprites.player.attack_left[2] = load_png(data, SPRITE_P_ATAK_LEFT3);
	data->sprites.player.attack_left[3] = load_png(data, SPRITE_P_ATAK_LEFT4);
	data->sprites.player.attack_right[0] = load_png(data, SPRITE_P_ATAK_RIGHT1);
	data->sprites.player.attack_right[1] = load_png(data, SPRITE_P_ATAK_RIGHT2);
	data->sprites.player.attack_right[2] = load_png(data, SPRITE_P_ATAK_RIGHT3);
	load_all_png2(data);
}
