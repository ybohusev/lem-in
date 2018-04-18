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
	nod_tmp->is_funk_room = mode;
	nod_tmp->next = NULL;
	nod_tmp->linked_nodes = NULL;
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

extern	t_graph	read_data(void)
{
	char	*line;
	t_nodes	*nodes;
	t_links *links;
	t_graph	graph;
	int		mode;

	line = NULL;
	nodes = NULL;
	links = NULL;
	while (get_next_line(0, &line))
	{
		if (!ft_strcmp(line, "##start"))
			mode = 1;
		else if (!ft_strcmp(line, "##end"))
			mode = 2;
		if (line[0] != '#' && !ft_strchr(line, '-'))
		{
			nodes = fill_nodes(line, nodes, mode);
			mode = 0;
		}
		else if (*line != '#' && ft_strchr(line, '-'))
			links = fill_links(line, links);
		free(line);
	}
	graph.nodes = nodes;
	graph.links = links;
	return (graph);
}
