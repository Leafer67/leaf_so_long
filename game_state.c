/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:50:23 by lloison           #+#    #+#             */
/*   Updated: 2022/11/29 15:14:16 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_data.h"
#include "renderer.h"
#include "parsing.h"

void	end_game(t_data *data, t_bool has_won)
{
	if (!data->game_end)
	{
		data->game_end = TRUE;
		display_end_menu(data, has_won);
		ft_printf("End of game\n");
		data->player.can_move = FALSE;
	}
}

void	close_game(void *ptr)
{
	t_data	*data;

	data = ptr;
	free_data(&data);
	exit(0);
}

void	restart_game(t_data **data)
{
	t_map	*tmp_map;
	mlx_t	*tmp_mlx;

	tmp_map = parse_map((*data)->argv);
	tmp_mlx = (*data)->mlx;
	reset_data(*data);
	*data = init_data(tmp_mlx, tmp_map);
	render_frame(*data);
}
