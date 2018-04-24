/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:17:20 by ybohusev          #+#    #+#             */
/*   Updated: 2018/04/14 16:17:21 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static	t_data	*clr_data(t_data *data)
{
	t_data	*tmp;

	tmp = data;
	while (data->next->str)
		data = data->next;
	free(data->next);	
	data->next = NULL;
	return (tmp);
}

int		main()
{
	t_graph	graph;
	t_data	*data;
	int		err;

	err = 0;
	data = read_data();
	if ((err = validation(data)))
		exeptions(err);
	if (err == INVALID_LINK)
		data = clr_data(data);
	graph = parse(data);
	link_nodes(graph);
	bfs(graph.nodes);
	while (graph.nodes)
	{
		printf("NAME %s\n", graph.nodes->name);
		printf("  %d\n", graph.nodes->color);
		graph.nodes = graph.nodes->next;
	}
	// system("leaks lem-in");
	return (0);
}
