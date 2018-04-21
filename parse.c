/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 14:12:28 by ybohusev          #+#    #+#             */
/*   Updated: 2018/04/15 14:12:29 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static	t_nodes	*fill_nodes(char *line, t_nodes *nodes, int mode)
{
	char	**tmp;
	t_nodes	*nod_tmp;
	t_nodes	*mov;

	mov = nodes;
	tmp = ft_strsplit(line, ' ');
	nod_tmp = (t_nodes*)malloc(sizeof(t_nodes));
	nod_tmp->name = ft_strdup(tmp[0]);
	nod_tmp->color = WHITE;
	nod_tmp->weight = 2147483647;
	nod_tmp->x = ft_atoi(tmp[1]);
	nod_tmp->y = ft_atoi(tmp[2]);
	nod_tmp->is_funk_room = mode;
	nod_tmp->next = NULL;
	nod_tmp->linked_nodes = NULL;
	nod_tmp->amount_links = 0;
	if (nodes == NULL)
	{
		nodes = nod_tmp;
		return (nodes);
	}
	while (nodes->next)
		nodes = nodes->next;
	nodes->next = nod_tmp;
	return (mov);
}

static	t_links	*fill_links(char *line, t_links *links)
{
	char 	**tmp;
	t_links	*links_tmp;
	t_links	*mov;

	mov = links;
	tmp = ft_strsplit(line, '-');
	links_tmp = (t_links*)malloc(sizeof(t_links));
	links_tmp->name1 = ft_strdup(tmp[0]);
	links_tmp->name2 = ft_strdup(tmp[1]);
	links_tmp->next = NULL;
	if (links == NULL)
	{
		links = links_tmp;
		return (links);
	}
	while (links->next)
		links = links->next;
	links->next = links_tmp;
	return (mov);
}

extern	t_graph	parse(t_data *data)
{
	t_nodes	*nodes;
	t_links *links;
	t_graph	graph;
	int		mode;

	nodes = NULL;
	links = NULL;
	while (data)
	{
		if (!ft_strcmp(data->str, "##start"))
			mode = 1;
		else if (!ft_strcmp(data->str, "##end"))
			mode = 2;
		if (data->str[0] != '#' && !ft_strchr(data->str, '-'))
		{
			nodes = fill_nodes(data->str, nodes, mode);
			mode = 0;
		}
		else if (data->str[0] != '#' && ft_strchr(data->str, '-'))
			links = fill_links(data->str, links);
		data = data->next;
	}
	graph.nodes = nodes;
	graph.links = links;
	return (graph);
}
