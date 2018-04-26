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

# include "./libft/libft.h"
# include <stdio.h>

# define WHITE 0
# define GRAY 1
# define BLACK 2

# define NO_ANTS 1
# define EMPTY_LINE 2
# define NO_DATA 3
# define INVALID_ROOMS 4
# define INVALID_START 5
# define INVALID_END 6
# define NO_ROOMS 7
# define INVALID_NAME 8
# define INVALID_COORDS 9
# define NO_LINKS 10
# define INVALID_LINK 11
# define NO_PATH 12

typedef struct s_table
{
	char 	*name;
	struct s_table	*next;
}				t_table;

typedef struct s_path
{
	char 	*name;
	int		ants;
	struct s_path	*next;
}				t_path;

typedef struct s_data
{
	char 	*str;
	struct s_data	*next;
}				t_data;

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

t_data	*read_data(void);
int		validation(t_data *data);
void	exeptions(int err);
int		is_valid_room(char *str, t_table **table);
int		is_valid_link(t_data *data, t_table *table);
int		is_link(char *str);

t_graph	parse(t_data *data);
void	link_nodes(t_graph graph);
void	bfs(t_nodes *nodes);
int		get_path(t_nodes *nodes, t_path **path);
void	display_path(t_path *path, t_data *data);

void	del_data(t_data *data);
void	del_table(t_table *table);

#endif
