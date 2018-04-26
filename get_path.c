/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 11:33:11 by ybohusev          #+#    #+#             */
/*   Updated: 2018/04/26 11:33:13 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static	t_path	*add_room(t_path *path, char *name, int ants)
{
	t_path		*tmp;
	t_path		*ret;

	ret = path;
	tmp = (t_path*)malloc(sizeof(t_path) * 1);
	tmp->name = ft_strdup(name);
	tmp->ants = ants;
	tmp->next = NULL;
	if (!path)
	{
		path = tmp;
		return (path);
	}
	while (path->next)
		path = path->next;
	path->next = tmp;
	return (ret);
}

static	int		min_weight(t_nodes *nodes)
{
	int		min;
	int		count;
	int		is_black;

	count = 0;
	min = 0;
	is_black = 0;
	while (count < nodes->amount_links)
	{	
		if (nodes->linked_nodes[count]->color == BLACK)
		{
			is_black = 1;
			if (nodes->linked_nodes[min]->weight > nodes->linked_nodes[count]->weight)
				min = count;
		}
		count++;
	}
	if (is_black == 0)
		return (-1);
	return (min);
}

static	int		shortest_path(t_nodes *nodes, t_path **path)
{
	int		next;

	next = 0;
	while ((next = min_weight(nodes)) >= 0)
	{
		*path = add_room(*path, nodes->name, nodes->ants);
		if (nodes->is_funk_room == 2)
			return (0);
		nodes = nodes->linked_nodes[next];
	}
	if (next == -1)
			return (NO_PATH);
	return (0);
}

extern	int		get_path(t_nodes *nodes, t_path **path)
{
	while (nodes->is_funk_room != 1)
		nodes = nodes->next;
	if (nodes->color == WHITE || nodes->color == GRAY)
		return (NO_PATH);
	// else
	// 	*path = add_room(*path, nodes->name, nodes->ants);
	shortest_path(nodes, path);
	return (0);
}
