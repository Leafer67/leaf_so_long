/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_path_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:08:00 by lloison           #+#    #+#             */
/*   Updated: 2022/12/07 14:18:45 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_data.h"
#include "enemy_behavior.h"
#include "parsing.h"

static void	exit_program(t_queue *queue, t_data *data,
	t_list *toclear, char *error_msg)
{
	if (queue)
		free_queue(&queue, free);
	if (data)
		free_data(&data);
	if (toclear)
		ft_lstclear(&toclear, free);
	ft_printf("%s\n", error_msg);
	exit(0);
}

int	reconstruct_path(t_node *end_node, t_enemy *enemy)
{
	t_pos	*content;
	t_list	*node;

	while (end_node->parent_node)
	{
		content = malloc(sizeof(t_pos));
		content->x = end_node->position.x;
		content->y = end_node->position.y;
		node = ft_lstnew(content);
		if (node == 0)
			return (-1);
		ft_lstadd_front(&(enemy->path), node);
		end_node = end_node->parent_node;
	}
	return (1);
}

void	add_toclear(t_data *data, t_queue *queue,
	t_list *toclear, t_node *to_add)
{
	t_list	*tmp;

	tmp = ft_lstnew(to_add);
	if (tmp == 0)
		exit_program(queue, data, toclear, "Malloc error");
	ft_lstadd_front(&toclear, tmp);
}

int	no_path_found(t_queue **queue, t_list **toclear)
{
	free_queue(queue, free);
	ft_lstclear(toclear, free);
	return (-1);
}
