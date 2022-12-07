/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 13:09:00 by lloison           #+#    #+#             */
/*   Updated: 2022/11/29 12:17:25 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

static void	exit_program(t_queue *queue, t_data *data, char *error_msg)
{
	if (queue)
		free_queue(&queue, free);
	if (data)
		free_data(&data);
	ft_printf("%s\n", error_msg);
	exit(0);
}

t_node	*create_node(t_data *data, t_queue *queue,
	t_pos node_pos, t_node *parent_node)
{
	t_node	*output;

	output = malloc(sizeof(t_node));
	if (output == 0)
		exit_program(queue, data, "Malloc error");
	output->parent_node = parent_node;
	output->position = node_pos;
	return (output);
}

void	free_queue(t_queue **queue, void (*del)(void *))
{
	t_queue	*temp;

	if (queue == 0)
		return ;
	if (*queue == 0 || del == 0)
		return ;
	temp = (*queue)->next;
	while (temp)
	{
		temp = (*queue)->next;
		if ((*queue)->content)
			del((*queue)->content);
		free(*queue);
		(*queue) = temp;
	}
	if (*queue != 0)
	{
		if ((*queue)->content)
			del((*queue)->content);
		free(*queue);
	}
	*queue = 0;
}

void	enqueue(t_data *data, t_queue **queue,
	t_pos node_pos, t_node *parent_node)
{
	t_queue	*last_elem;
	t_queue	*new_elem;

	if (queue == 0 || *queue == 0)
	{
		*queue = malloc(sizeof(t_queue));
		if (*queue == 0)
			exit_program(0, data, "Malloc error");
		(*queue)->content = create_node(data, *queue, node_pos, parent_node);
		(*queue)->next = 0;
		return ;
	}
	new_elem = malloc(sizeof(t_queue));
	if (new_elem == 0)
		exit_program(*queue, data, "Malloc error");
	new_elem->content = create_node(data, *queue, node_pos, parent_node);
	new_elem->next = 0;
	last_elem = *queue;
	while (last_elem->next)
		last_elem = last_elem->next;
	last_elem->next = new_elem;
}

t_node	*dequeue(t_data *data, t_queue **queue)
{
	t_queue	*tmp;
	t_node	*output;

	if (*queue == 0)
		exit_program(0, data, "Trying to dequeue an empty queue");
	tmp = *queue;
	output = (*queue)->content;
	*queue = (*queue)->next;
	free(tmp);
	return (output);
}
