/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:10:20 by lloison           #+#    #+#             */
/*   Updated: 2022/12/07 15:49:06 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define TRUE 1
# define FALSE 0

typedef char	t_bool;
typedef enum e_direction {down, up, left, right}	t_direction;
typedef enum e_corner {top_left, top_right, bot_left, bot_right}	t_corner;
typedef enum e_player_action {idle, walk, attack, death}	t_player_action;
typedef enum e_ai_state {patrol, chase, guard, e_death, stuck}	t_ai_state;

# define WINDOW_WIDTH 2560
# define WINDOW_HEIGHT 1280

# define MAX_SIZE_X 40
# define MAX_SIZE_Y 20

# define SPRITE_END_FILE "./sprites/end.png"
# define SPRITE_WALL_FILE "./sprites/wall.png"
# define SPRITE_ITEM01_FILE "./sprites/item/item01.png"
# define SPRITE_ITEM02_FILE "./sprites/item/item02.png"
# define SPRITE_ITEM03_FILE "./sprites/item/item03.png"
# define SPRITE_ITEM04_FILE "./sprites/item/item04.png"
# define SPRITE_ITEM05_FILE "./sprites/item/item05.png"
# define SPRITE_ITEM06_FILE "./sprites/item/item06.png"
# define SPRITE_GROUND_FILE "./sprites/ground.png"

# define SPRITE_P_IDLE_UP1 "./sprites/player/idle/player_idle_up1.png"
# define SPRITE_P_IDLE_UP2 "./sprites/player/idle/player_idle_up2.png"
# define SPRITE_P_IDLE_UP3 "./sprites/player/idle/player_idle_up3.png"
# define SPRITE_P_IDLE_UP4 "./sprites/player/idle/player_idle_up4.png"
# define SPRITE_P_IDLE_DOWN1 "./sprites/player/idle/player_idle_down1.png"
# define SPRITE_P_IDLE_DOWN2 "./sprites/player/idle/player_idle_down2.png"
# define SPRITE_P_IDLE_DOWN3 "./sprites/player/idle/player_idle_down3.png"
# define SPRITE_P_IDLE_DOWN4 "./sprites/player/idle/player_idle_down4.png"
# define SPRITE_P_IDLE_LEFT1 "./sprites/player/idle/player_idle_left1.png"
# define SPRITE_P_IDLE_LEFT2 "./sprites/player/idle/player_idle_left2.png"
# define SPRITE_P_IDLE_LEFT3 "./sprites/player/idle/player_idle_left3.png"
# define SPRITE_P_IDLE_LEFT4 "./sprites/player/idle/player_idle_left4.png"
# define SPRITE_P_IDLE_RIGHT1 "./sprites/player/idle/player_idle_right1.png"
# define SPRITE_P_IDLE_RIGHT2 "./sprites/player/idle/player_idle_right2.png"
# define SPRITE_P_IDLE_RIGHT3 "./sprites/player/idle/player_idle_right3.png"
# define SPRITE_P_IDLE_RIGHT4 "./sprites/player/idle/player_idle_right4.png"

# define SPRITE_P_ATAK_UP1 "./sprites/player/attack/player_attack_up1.png"
# define SPRITE_P_ATAK_UP2 "./sprites/player/attack/player_attack_up2.png"
# define SPRITE_P_ATAK_UP3 "./sprites/player/attack/player_attack_up3.png"
# define SPRITE_P_ATAK_UP4 "./sprites/player/attack/player_attack_up4.png"
# define SPRITE_P_ATAK_DOWN1 "./sprites/player/attack/player_attack_down1.png"
# define SPRITE_P_ATAK_DOWN2 "./sprites/player/attack/player_attack_down2.png"
# define SPRITE_P_ATAK_DOWN3 "./sprites/player/attack/player_attack_down3.png"
# define SPRITE_P_ATAK_DOWN4 "./sprites/player/attack/player_attack_down4.png"
# define SPRITE_P_ATAK_LEFT1 "./sprites/player/attack/player_attack_left1.png"
# define SPRITE_P_ATAK_LEFT2 "./sprites/player/attack/player_attack_left2.png"
# define SPRITE_P_ATAK_LEFT3 "./sprites/player/attack/player_attack_left3.png"
# define SPRITE_P_ATAK_LEFT4 "./sprites/player/attack/player_attack_left4.png"
# define SPRITE_P_ATAK_RIGHT1 "./sprites/player/attack/player_attack_right1.png"
# define SPRITE_P_ATAK_RIGHT2 "./sprites/player/attack/player_attack_right2.png"
# define SPRITE_P_ATAK_RIGHT3 "./sprites/player/attack/player_attack_right3.png"
# define SPRITE_P_ATAK_RIGHT4 "./sprites/player/attack/player_attack_right4.png"

# define SPRITE_P_WALK_UP1 "./sprites/player/walk/player_walk_up1.png"
# define SPRITE_P_WALK_UP2 "./sprites/player/walk/player_walk_up2.png"
# define SPRITE_P_WALK_UP3 "./sprites/player/walk/player_walk_up3.png"
# define SPRITE_P_WALK_UP4 "./sprites/player/walk/player_walk_up4.png"
# define SPRITE_P_WALK_DOWN1 "./sprites/player/walk/player_walk_down1.png"
# define SPRITE_P_WALK_DOWN2 "./sprites/player/walk/player_walk_down2.png"
# define SPRITE_P_WALK_DOWN3 "./sprites/player/walk/player_walk_down3.png"
# define SPRITE_P_WALK_DOWN4 "./sprites/player/walk/player_walk_down4.png"
# define SPRITE_P_WALK_LEFT1 "./sprites/player/walk/player_walk_left1.png"
# define SPRITE_P_WALK_LEFT2 "./sprites/player/walk/player_walk_left2.png"
# define SPRITE_P_WALK_LEFT3 "./sprites/player/walk/player_walk_left3.png"
# define SPRITE_P_WALK_LEFT4 "./sprites/player/walk/player_walk_left4.png"
# define SPRITE_P_WALK_RIGHT1 "./sprites/player/walk/player_walk_right1.png"
# define SPRITE_P_WALK_RIGHT2 "./sprites/player/walk/player_walk_right2.png"
# define SPRITE_P_WALK_RIGHT3 "./sprites/player/walk/player_walk_right3.png"
# define SPRITE_P_WALK_RIGHT4 "./sprites/player/walk/player_walk_right4.png"

# define SPRITE_P_DEATH1 "./sprites/player/death/player_death1.png"
# define SPRITE_P_DEATH2 "./sprites/player/death/player_death2.png"
# define SPRITE_P_DEATH3 "./sprites/player/death/player_death3.png"
# define SPRITE_P_DEATH4 "./sprites/player/death/player_death4.png"

# define SPRITE_E_WALK_LEFT1 "./sprites/enemy/walk/enemy_walk_left1.png"
# define SPRITE_E_WALK_LEFT2 "./sprites/enemy/walk/enemy_walk_left2.png"
# define SPRITE_E_WALK_LEFT3 "./sprites/enemy/walk/enemy_walk_left3.png"
# define SPRITE_E_WALK_LEFT4 "./sprites/enemy/walk/enemy_walk_left4.png"
# define SPRITE_E_WALK_LEFT5 "./sprites/enemy/walk/enemy_walk_left5.png"
# define SPRITE_E_WALK_LEFT6 "./sprites/enemy/walk/enemy_walk_left6.png"

# define SPRITE_E_WALK_RIGHT1 "./sprites/enemy/walk/enemy_walk_right1.png"
# define SPRITE_E_WALK_RIGHT2 "./sprites/enemy/walk/enemy_walk_right2.png"
# define SPRITE_E_WALK_RIGHT3 "./sprites/enemy/walk/enemy_walk_right3.png"
# define SPRITE_E_WALK_RIGHT4 "./sprites/enemy/walk/enemy_walk_right4.png"
# define SPRITE_E_WALK_RIGHT5 "./sprites/enemy/walk/enemy_walk_right5.png"
# define SPRITE_E_WALK_RIGHT6 "./sprites/enemy/walk/enemy_walk_right6.png"

# define SPRITE_E_CHASE_LEFT1 "./sprites/enemy/chase/enemy_chase_left1.png"
# define SPRITE_E_CHASE_LEFT2 "./sprites/enemy/chase/enemy_chase_left2.png"
# define SPRITE_E_CHASE_LEFT3 "./sprites/enemy/chase/enemy_chase_left3.png"
# define SPRITE_E_CHASE_LEFT4 "./sprites/enemy/chase/enemy_chase_left4.png"
# define SPRITE_E_CHASE_LEFT5 "./sprites/enemy/chase/enemy_chase_left5.png"
# define SPRITE_E_CHASE_LEFT6 "./sprites/enemy/chase/enemy_chase_left6.png"

# define SPRITE_E_CHASE_RIGHT1 "./sprites/enemy/chase/enemy_chase_right1.png"
# define SPRITE_E_CHASE_RIGHT2 "./sprites/enemy/chase/enemy_chase_right2.png"
# define SPRITE_E_CHASE_RIGHT3 "./sprites/enemy/chase/enemy_chase_right3.png"
# define SPRITE_E_CHASE_RIGHT4 "./sprites/enemy/chase/enemy_chase_right4.png"
# define SPRITE_E_CHASE_RIGHT5 "./sprites/enemy/chase/enemy_chase_right5.png"
# define SPRITE_E_CHASE_RIGHT6 "./sprites/enemy/chase/enemy_chase_right6.png"

# define SPRITE_E_DEATH_LEFT1 "./sprites/enemy/death/enemy_death_left1.png"
# define SPRITE_E_DEATH_LEFT2 "./sprites/enemy/death/enemy_death_left2.png"
# define SPRITE_E_DEATH_LEFT3 "./sprites/enemy/death/enemy_death_left3.png"
# define SPRITE_E_DEATH_LEFT4 "./sprites/enemy/death/enemy_death_left4.png"
# define SPRITE_E_DEATH_LEFT5 "./sprites/enemy/death/enemy_death_left5.png"
# define SPRITE_E_DEATH_LEFT6 "./sprites/enemy/death/enemy_death_left6.png"
# define SPRITE_E_DEATH_LEFT7 "./sprites/enemy/death/enemy_death_left7.png"
# define SPRITE_E_DEATH_LEFT8 "./sprites/enemy/death/enemy_death_left8.png"

# define SPRITE_E_DEATH_RIGHT1 "./sprites/enemy/death/enemy_death_right1.png"
# define SPRITE_E_DEATH_RIGHT2 "./sprites/enemy/death/enemy_death_right2.png"
# define SPRITE_E_DEATH_RIGHT3 "./sprites/enemy/death/enemy_death_right3.png"
# define SPRITE_E_DEATH_RIGHT4 "./sprites/enemy/death/enemy_death_right4.png"
# define SPRITE_E_DEATH_RIGHT5 "./sprites/enemy/death/enemy_death_right5.png"
# define SPRITE_E_DEATH_RIGHT6 "./sprites/enemy/death/enemy_death_right6.png"
# define SPRITE_E_DEATH_RIGHT7 "./sprites/enemy/death/enemy_death_right7.png"
# define SPRITE_E_DEATH_RIGHT8 "./sprites/enemy/death/enemy_death_right8.png"

# define SPRITE_WIDTH 64
# define SPRITE_HEIGHT 64

//Player pixel point
# define PLAYER_POS_SHIFT_X 47
# define PLAYER_POS_SHIFT_Y 62
# define PLAYER_HITBOX_TOP 57
# define PLAYER_HITBOX_BOT 68
# define PLAYER_HITBOX_LEFT 39
# define PLAYER_HITBOX_RIGHT 56

//Enemy pixel point
# define ENEMY_POS_SHIFT_X 32
# define ENEMY_POS_SHIFT_Y 32
# define ENEMY_HITBOX_TOP 22
# define ENEMY_HITBOX_BOT 56
# define ENEMY_HITBOX_LEFT 10
# define ENEMY_HITBOX_RIGHT 54

# define ENEMY_PATH_UPDATE_TIME 0.2

# define PLAYER_SPEED 300
# define ENEMY_PATROL_SPEED 150;
# define ENEMY_CHASE_SPEED 500; 

# define UI_REFRESH_TIME 0.2
# define ITEM_ANIMATION_SPEED 0.1
# define PLAYER_ANIMATION_SPEED 0.15
# define E_ANIM_SPEED 0.15

# define DETECTION_DISTANCE 300

#endif