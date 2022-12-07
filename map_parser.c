/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:18:57 by lloison           #+#    #+#             */
/*   Updated: 2022/11/28 10:50:10 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	exit_program(int fd, t_list **list, t_map *map, char *error_msg)
{
	if (fd != 0)
		close(fd);
	ft_lstclear(list, free);
	if (map != 0)
		free_map(&map);
	ft_printf("Error\n");
	ft_printf("%s\n", error_msg);
	exit(0);
}

t_bool	is_line_valid(char *tmp_line, size_t length)
{
	size_t	i;

	if (ft_strlen(tmp_line) != length)
		return (FALSE);
	i = 0;
	while (i < length - 1)
	{
		if (tmp_line[i] != '0' && tmp_line[i] != '1'
			&& tmp_line[i] != 'C' && tmp_line[i] != 'E' && tmp_line[i] != 'P'
			&& tmp_line[i] != 'U' && tmp_line[i] != 'D' && tmp_line[i] != 'R'
			&& tmp_line[i] != 'L')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_list	*get_data(char *file)
{
	t_list	*map_lines;
	int		fd;
	char	*tmp_line;
	void	*tmp_node;
	size_t	length;

	map_lines = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1 || fd == 0)
		exit_program(0, 0, 0, "Invalid file");
	tmp_line = get_next_line(fd);
	if (tmp_line == 0)
		exit_program(fd, &map_lines, 0, "File empty or malloc error");
	length = ft_strlen(tmp_line);
	while (tmp_line)
	{
		if (is_line_valid(tmp_line, length) == FALSE)
			exit_program(fd, &map_lines, 0, "Invalid map format");
		tmp_node = ft_lstnew(tmp_line);
		if (tmp_node == 0)
			exit_program(fd, &map_lines, 0, "Malloc error");
		ft_lstadd_back(&map_lines, tmp_node);
		tmp_line = get_next_line(fd);
	}
	return (map_lines);
}

t_map	*data_to_map(t_list **map_lines)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (map == 0)
		exit_program(0, map_lines, 0, "Malloc error");
	map->size.x = ft_strlen((*map_lines)->content) - 1;
	map->size.y = ft_lstsize(*map_lines);
	if (map->size.x > MAX_SIZE_X || map->size.y > MAX_SIZE_Y)
		exit_program(0, map_lines, map, "Map is too big (max size is 78x43)");
	data_to_tiles(map, map_lines);
	get_start_pos(map);
	check_if_map_is_enclosed(map);
	get_end_pos(map);
	get_nb_items_enemies(map);
	get_enemies_pos_dir(map);
	get_items_pos(map);
	has_valid_path(map);
	return (map);
}

t_map	*parse_map(char *file)
{
	t_list	*map_data;
	t_map	*map;

	check_file_name(file);
	map_data = get_data(file);
	map = data_to_map(&map_data);
	ft_lstclear(&map_data, free);
	return (map);
}
