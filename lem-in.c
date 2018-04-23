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

int		main()
{
	// t_graph	graph;
	t_data	*data;
	int		err;

	err = 0;
	data = read_data();
	if ((err = validation(data)))
		exeptions(err);
	while (data)
	{
		printf("%s\n", data->str);
		data = data->next;
	}
	// graph = parse(data);
	// link_nodes(graph);
	// bfs(graph.nodes);
	system("leaks lem-in");
	return (0);
}
