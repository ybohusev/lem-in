/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:07:14 by ybohusev          #+#    #+#             */
/*   Updated: 2018/04/20 14:07:15 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static	void	add_to_queue(t_nodes *node, t_queue *queue)
{
	t_queue	*tmp;

	tmp = (t_queue*)malloc(sizeof(t_queue) * 1);
	tmp->curr = node;
	tmp->curr->color = GRAY;
	tmp->next = NULL;
	while (queue->next)
		queue = queue->next;
	queue->next = tmp;
}

static	t_queue	*init_queue(t_nodes *node)
{
	t_queue	*queue;

	queue = (t_queue*)malloc(sizeof(t_queue) * 1);
	queue->curr = node;
	queue->curr->color = GRAY;
	queue->curr->weight = 0;
	queue->next = NULL;
	return (queue);
}

static	void	del_fqueue(t_queue **queue)
{
	t_queue	*tmp;

	tmp = (*queue)->next;
	free(*queue);
	(*queue) = tmp;
}

static	void	see_queue(t_queue **queue)
{
	int		count;

	count = 0;
	while (count < (*queue)->curr->amount_links)
	{
		if ((*queue)->curr->linked_nodes[count]->color == WHITE)
		{
			(*queue)->curr->linked_nodes[count]->weight = (*queue)->curr->weight + 1;
			add_to_queue((*queue)->curr->linked_nodes[count], (*queue));
		}
		count++;
	}
	(*queue)->curr->color = BLACK;
	del_fqueue(queue);
}

extern	void	bfs(t_nodes *nodes)
{
	t_queue	*queue;

	while (nodes->is_funk_room != 2)
		nodes = nodes->next;
	queue = init_queue(nodes);
	while (queue)
	{
		see_queue(&queue);
	}
	return ;
}
