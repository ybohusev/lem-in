/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 15:29:03 by ybohusev          #+#    #+#             */
/*   Updated: 2018/04/15 15:29:05 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static	t_nodes	*find_node(char *name, t_nodes *all_nodes)
{
	while (all_nodes)
	{
		if (!ft_strcmp(all_nodes->name, name))
			return (all_nodes);
		all_nodes = all_nodes->next;
	}
	return (NULL);
}

static	void	link_one_node(t_nodes *node, t_links *links, t_nodes *all_nodes)
{
	int		count;

	count = 0;
	while (count < node->amount_links)
	{
		if (!ft_strcmp(node->name, links->name1))
		{
			node->linked_nodes[count] = find_node(links->name2, all_nodes);
			count++;
		}
		else if (!ft_strcmp(node->name, links->name2))
		{
			node->linked_nodes[count] = find_node(links->name1, all_nodes);
			count++;
		}
		links = links->next;
	}	
}

static	void	count_links(t_nodes *node, t_links *links, t_nodes *all_nodes)
{
	t_links	*tmp;

	tmp = links;
	while (tmp)
	{
		if (!ft_strcmp(node->name, tmp->name1) || !ft_strcmp(node->name, tmp->name2))
			node->amount_links++;
		tmp = tmp->next;
	}
	node->linked_nodes = (t_nodes**)malloc(sizeof(t_nodes*) * node->amount_links + 1);
	node->linked_nodes[node->amount_links] = NULL;
	link_one_node(node, links, all_nodes);
}

extern	void	link_nodes(t_graph graph)
{
	t_nodes *nodes;

	nodes = graph.nodes;
	while (graph.nodes)
	{
		count_links(graph.nodes, graph.links, nodes);
		graph.nodes = graph.nodes->next;
	}
	graph.nodes = nodes;
	return ;
}
