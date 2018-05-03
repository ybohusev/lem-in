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

#include "lem_in.h"

static	t_links	*fill_links(char *line, t_links *links)
{
	char	**tmp;
	t_links	*links_tmp;
	t_links	*mov;

	mov = links;
	tmp = ft_strsplit(line, '-');
	links_tmp = (t_links*)malloc(sizeof(t_links));
	links_tmp->name1 = tmp[0];
	links_tmp->name2 = tmp[1];
	links_tmp->next = NULL;
	free(tmp);
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

static	int		get_mode(char *str, int mode)
{
	if (!ft_strcmp(str, "##start"))
		return (1);
	else if (!ft_strcmp(str, "##end"))
		return (2);
	return (mode);
}

extern	t_graph	parse(t_data *data)
{
	t_graph	graph;
	int		mode;
	int		ants;

	graph.nodes = NULL;
	graph.links = NULL;
	if (!data)
		return (graph);
	ants = ft_atoi(data->str);
	data = data->next;
	mode = 0;
	while (data && data->is_err != 1)
	{
		mode = get_mode(data->str, mode);
		if (data->str[0] != '#' && !ft_strchr(data->str, '-'))
		{
			graph.nodes = fill_nodes(data->str, graph.nodes, mode, ants);
			mode = 0;
		}
		else if (data->str[0] != '#' && ft_strchr(data->str, '-'))
			graph.links = fill_links(data->str, graph.links);
		data = data->next;
	}
	return (graph);
}
