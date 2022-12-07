/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 10:48:43 by lloison           #+#    #+#             */
/*   Updated: 2022/11/29 17:03:05 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "parsing.h"
#include "input.h"

void	debug_display_map_tiles(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size.y)
	{
		ft_printf("%s\n", map->tiles[i]);
		i++;
	}
}

void	debug_display_map_items_pos(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->nb_items)
	{
		ft_printf("item %d : %dx/%dy\n", i, map->items_pos[i].x,
			map->items_pos[i].y);
		i++;
	}
}

void	debug_display_enemies(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->enemy_count)
	{
		ft_printf("enemy %d :\n\tpos : %dx/%dy\n", i,
			data->enemies[i].tile_pos.x, data->enemies[i].tile_pos.y);
		i++;
	}
}

void	debug_display_all_pos(t_map *map)
{
	ft_printf("start : %dx/%dy\n", map->start_pos.x, map->start_pos.y);
	ft_printf("start : %dx/%dy\n", map->exit_pos.x, map->exit_pos.y);
	debug_display_map_items_pos(map);
}

// END OF DEBUG FUNCTIONS

int	main(int argc, char **argv)
{
	t_map	*map;
	mlx_t	*mlx;
	t_data	*data;

	if (argc == 2)
	{
		mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "So long", FALSE);
		if (!mlx)
			return (0);
		map = parse_map(argv[1]);
		data = init_data(mlx, map);
		render_frame(data);
		mlx_loop_hook(data->mlx, handle_input, &data);
		mlx_close_hook(data->mlx, close_game, data);
		mlx_loop(data->mlx);
		free_data(&data);
	}
	else
		ft_printf("Wrong argument count\n");
	return (0);
}

//Debug main
//int	main(int argc, char **argv)
//{
//	t_map	*map;
//
//	(void)argc;
//	map = parse_map(argv[1]);
//	debug_display_map_tiles(map);
//	debug_display_map_items_pos(map);
//	free_map(map);
//	return (0);
//}
