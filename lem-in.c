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

// static	t_data	*clr_data(t_data *data)
// {
// 	t_data	*tmp;

// 	tmp = data;
// 	while (data->next->str)
// 		data = data->next;
// 	free(data->next);	
// 	data->next = NULL;
// 	return (tmp);
// }

int		main()
{
	// t_graph	graph;
	t_data	*data;
	int		err;
	t_path	*path;

	err = 0;
	path = NULL;
	data = read_data();
	if ((err = validation(data)))
		exeptions(err);
	// if (err == INVALID_LINK)
	// 	data = clr_data(data);
	// graph = parse(data);
	// link_nodes(graph);
	// bfs(graph.nodes);
	// if ((err = get_path(graph.nodes, &path)))
	// 	exeptions(err, data);
	// display_path(path, data);
	// del_data(data);
	// system("leaks lem-in");
	return (0);
}
