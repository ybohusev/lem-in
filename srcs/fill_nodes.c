/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 17:25:40 by ybohusev          #+#    #+#             */
/*   Updated: 2018/05/03 17:27:04 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	t_nodes	*add_node(char *line, int mode, int ants)
{
	t_nodes	*nod_tmp;
	char	**tmp;

	tmp = ft_strsplit(line, ' ');
	nod_tmp = (t_nodes*)malloc(sizeof(t_nodes));
	nod_tmp->name = tmp[0];
	nod_tmp->color = WHITE;
	nod_tmp->weight = 2147483647;
	if (mode == 1)
		nod_tmp->ants = ants;
	else
		nod_tmp->ants = 0;
	nod_tmp->x = ft_atoi(tmp[1]);
	nod_tmp->y = ft_atoi(tmp[2]);
	nod_tmp->is_funk_room = mode;
	nod_tmp->next = NULL;
	nod_tmp->linked_nodes = NULL;
	nod_tmp->amount_links = 0;
	free(tmp[1]);
	free(tmp[2]);
	free(tmp);
	return (nod_tmp);
}

extern	t_nodes	*fill_nodes(char *line, t_nodes *nodes, int mode, int ants)
{
	t_nodes	*nod_tmp;
	t_nodes	*mov;

	mov = nodes;
	nod_tmp = add_node(line, mode, ants);
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
