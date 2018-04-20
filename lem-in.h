/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:17:26 by ybohusev          #+#    #+#             */
/*   Updated: 2018/04/14 16:17:28 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <stdio.h>

# define WHITE 0
# define GRAY 1
# define BLACK 2

typedef struct s_links
{
	char 	*name1;
	char	*name2;
	struct s_links	*next;
}				t_links;

typedef struct s_nodes
{
	char 	*name;
	int		ants;
	int		x;
	int		y;
	int		color;
	int		weight;
	int		is_funk_room; /*0 - usual room, 1 - start, 2 - end*/
	struct s_nodes	*next;
	int		amount_links;
	struct s_nodes	**linked_nodes;
}				t_nodes;

typedef struct s_graph
{
	t_links	*links;
	t_nodes	*nodes;
}				t_graph;

typedef struct s_queue
{
	t_nodes	*curr;
	struct s_queue	*next;
}				t_queue;

t_graph	read_data(void);


void	link_nodes(t_graph graph);


void	bfs(t_nodes *nodes);


#endif
