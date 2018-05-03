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

#include "lem_in.h"

extern	int		main(void)
{
	t_graph	graph;
	t_data	*data;
	int		err;
	t_path	*path;

	err = 0;
	path = NULL;
	data = read_data();
	if ((err = validation(data)))
		exeptions(err);
	graph = parse(data);
	link_nodes(graph);
	bfs(graph.nodes);
	if ((err = get_path(graph.nodes, &path)))
		exeptions(err);
	display_path(path, data);
	return (0);
}
