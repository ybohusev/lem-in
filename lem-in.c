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

t_nodes	*fill_nodes(char *line)
{
	printf("%s\n", line);
	printf("HERE\n");
}

t_graph	*read_data()
{
	char	*line;
	t_graph	*graph;

	line = NULL;
	graph = NULL;
	while (get_next_line(0, &line))
	{
		if (*line != '#' && !ft_strchr(line, '-'))
			graph->nodes = fill_nodes(line);
		free(line);
	}

}

int		main(int argc, char const **argv)
{
	t_graph	*graph;

	graph = read_data();
	return (0);
}
