/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 13:09:16 by lloison           #+#    #+#             */
/*   Updated: 2022/11/27 14:13:39 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include "t_data.h"

typedef struct s_node
{
	t_pos			position;
	struct s_node	*parent_node;
}	t_node;

typedef struct s_queue
{
	t_node			*content;
	struct s_queue	*next;
}	t_queue;

t_node	*create_node(t_data *data, t_queue *queue,
			t_pos node_pos, t_node *parent_node);
void	free_queue(t_queue **queue, void (*del)(void *));
void	enqueue(t_data *data, t_queue **queue,
			t_pos node_pos, t_node *parent_node);
t_node	*dequeue(t_data *data, t_queue **queue);
#endif