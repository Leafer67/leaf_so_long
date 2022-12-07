/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_attack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:50:22 by lloison           #+#    #+#             */
/*   Updated: 2022/12/07 15:45:26 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_data.h"
#include "input.h"

void	player_attack(t_data *data)
{
	if (data->player.can_move)
	{
		data->player.can_move = FALSE;
		data->player.is_attacking = TRUE;
		data->player.action = attack;
	}
}
