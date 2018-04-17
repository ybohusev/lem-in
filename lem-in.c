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

int		main(int argc, char const **argv)
{
	t_graph	graph;
	t_path	*path;

	graph = read_data();
	link_nodes(graph);
	find_len(graph.links, graph.nodes);
	path = find_path(graph);
	return (0);
}
