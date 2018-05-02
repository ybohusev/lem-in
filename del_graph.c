/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_graph.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 13:22:45 by ybohusev          #+#    #+#             */
/*   Updated: 2018/05/02 13:22:47 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static	void	del_last_node(t_nodes **nodes)
{
	t_nodes *tmp;

	tmp = *nodes;
	if (tmp->next == NULL)
	{
		free(tmp);
		return ;
	}
	while (tmp->next->next)
		tmp = tmp->next;
	// free(tmp->next->linked_nodes);
	free(tmp->next->name);
	free(tmp->next);
	tmp->next = NULL;
}

static	void	del_nodes(t_nodes **nodes)
{
	if (!*nodes)
		return ;
	if ((*nodes)->next == NULL)
	{
		free((*nodes)->name);
		free(*nodes);
		return ;
	}
	while ((*nodes)->next)
		del_last_node(nodes);
	free((*nodes)->name);
	free(*nodes);
}

static	void	del_links(t_links *links)
{
	if (!links)
		return ;
	if (links->next)
		del_links(links->next);
	if (links->name1)
	{
		free(links->name1);
		links->name1 = NULL;
	}
	if (links->name2)
	{
		free(links->name2);
		links->name2 = NULL;
	}
	free(links);
	links = NULL;
}

extern	void	del_graph(t_graph graph)
{
	del_nodes(&graph.nodes);
	del_links(graph.links);
}
