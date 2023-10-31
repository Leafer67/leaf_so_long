/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:17:55 by lloison           #+#    #+#             */
/*   Updated: 2022/11/29 14:07:04 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "defines.h"
# include "MLX42/include/MLX42/MLX42.h"
# include "map.h"
# include "t_data.h"

int			create_trgb(int t, int r, int g, int b);
void		handle_animation(t_data *data, double time);
void		player_animation(t_data *data, double time);
void		enemies_animation(t_data *data, double time);
void		update_ui(t_data *data, t_bool force_upade, double time);
void		update_texts(t_data *data);
void		update_timer(t_data *data);
void		display_end_menu(t_data *data, t_bool won);
void		put_player_sprites(t_data *data);
void		disable_all_instances(t_data *data, int i);
void		put_enemies_sprites(t_data *data);
void		put_correct_sprite(t_data *data, t_pos pos, int x, int y);
void		render_frame(t_data *data);
void		disabled_images_to_pos(t_data *data, t_pos pos, int img_count, ...);
mlx_image_t	*get_correct_player_sprite(t_data *data, int index);
mlx_image_t	*get_correct_enemy_sprite(t_data *data, t_enemy	*e);

#endif