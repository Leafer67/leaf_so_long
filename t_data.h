/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_data.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:49:21 by lloison           #+#    #+#             */
/*   Updated: 2022/12/07 18:01:02 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_DATA_H
# define T_DATA_H

# include "defines.h"
# include "MLX42/MLX42.h"
# include <stdlib.h>
# include "libft/libft_e.h"
# include "map.h"
# include <math.h>

typedef struct s_item_sprites
{
	mlx_image_t	*i[6];
	t_bool		collected[6];
	int			image_index;
}	t_item_sprites;

typedef struct s_char_sprites
{
	mlx_image_t	*idle_up[4];
	mlx_image_t	*idle_down[4];
	mlx_image_t	*idle_left[4];
	mlx_image_t	*idle_right[4];
	mlx_image_t	*walk_up[4];
	mlx_image_t	*walk_down[4];
	mlx_image_t	*walk_left[4];
	mlx_image_t	*walk_right[4];
	mlx_image_t	*attack_up[4];
	mlx_image_t	*attack_down[4];
	mlx_image_t	*attack_left[4];
	mlx_image_t	*attack_right[4];
	mlx_image_t	*death[4];
	mlx_image_t	*curr_sprite;
}	t_char_sprites;

typedef struct s_enemy_sprites
{
	mlx_image_t		*walk_left[6];
	mlx_image_t		*walk_right[6];
	mlx_image_t		*chase_left[6];
	mlx_image_t		*chase_right[6];
	mlx_image_t		*death_left[8];
	mlx_image_t		*death_right[8];
	mlx_instance_t	**curr_instance;
}	t_enemy_sprites;

typedef struct s_sprites
{
	mlx_image_t		*wall;
	mlx_image_t		*end;
	t_char_sprites	player;
	t_enemy_sprites	enemy;
	mlx_image_t		*ground;
	t_item_sprites	item;
}	t_sprites;

typedef struct s_ui_images
{
	mlx_image_t	*mouvement_counter;
	mlx_image_t	*item_counter;
	mlx_image_t	*timer;
	mlx_image_t	*background;
	mlx_image_t	*end_text;
}	t_ui_images;

typedef struct s_enemy_animation
{
	t_ai_state	last_state;
	t_direction	last_direction;
	double		last_update;
	int			sprite_index;
}	t_enemy_animation;

typedef struct s_enemy
{
	t_pos				tile_pos;
	t_pos				pixel_pos;
	t_bool				can_move;
	t_ai_state			state;
	t_direction			direction;
	t_list				*path;
	t_enemy_animation	anim;
	t_bool				is_contact;
}	t_enemy;

typedef struct s_player
{
	t_pos			tile_pos;
	t_pos			pixel_pos;
	t_bool			can_move;
	t_player_action	action;
	t_direction		direction;
	t_bool			is_attacking;
}	t_player;

typedef struct s_data
{
	mlx_t			*mlx;
	t_sprites		sprites;
	t_ui_images		ui_images;
	t_player		player;
	t_enemy			*enemies;
	t_map			*map;
	t_pos			start_pos;
	t_bool			end_activated;
	t_bool			game_end;
	int				item_collected;
	int				movement_count;
	int				enemy_count;
	double			delta_time;
	double			timer;
}	t_data;

mlx_image_t	*load_png(t_data *data, char *filepath);
void		load_all_png(t_data *data);
int			get_item_index(t_data *data, t_pos item_pos);
void		free_data(t_data **data);
void		free_sprites(t_data *data, int img_count, ...);
void		reset_data(t_data *data);
void		free_ui(t_data *data);
t_data		*init_data(mlx_t *mlx, t_map *map);
void		init_ui(t_data *data);
t_pos		generate_sprite_pos(t_data *data, int x, int y);
t_pos		generate_player_sprite_pos(t_data *data, int x, int y);
t_pos		pos(int x, int y);
t_bool		is_egal(t_pos pos1, t_pos pos2);

#endif