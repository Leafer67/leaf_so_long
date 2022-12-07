/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 09:40:48 by lloison           #+#    #+#             */
/*   Updated: 2022/11/28 10:58:33 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "defines.h"
# include <fcntl.h>
# include <stdlib.h>
# include "map.h"
# include "t_data.h"

// Toutes les fonctions pour le pathfinding
void	reset_visited(t_bool **visited, t_map *map);
t_bool	**init_visited(t_map *map);
t_bool	search_for_item(t_pos start_pos, t_pos end_pos,
			t_map *map, t_bool **visited);
t_bool	search_for_end(int x, int y, t_map *map, t_bool **visited);
void	has_valid_path(t_map *map);
void	get_items_pos(t_map *map);
void	get_nb_items_enemies(t_map *map);
void	get_enemies_pos_dir(t_map *map);
void	get_end_pos(t_map *map);
void	check_if_map_is_enclosed(t_map *map);
void	get_start_pos(t_map *map);
void	data_to_tiles(t_map *map, t_list **map_lines);
t_map	*data_to_map(t_list **map_lines);
t_bool	is_line_valid(char *tmp_line, size_t length);
t_list	*get_data(char *file);
t_map	*parse_map(char *file);
void	check_file_name(char *file);

#endif