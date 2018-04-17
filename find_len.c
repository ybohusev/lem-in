/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:54:02 by ybohusev          #+#    #+#             */
/*   Updated: 2018/04/17 14:54:03 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static	double	get_len(t_nodes *first, t_nodes *second)
{
	double	ka_x;
	double	ka_y;
	double	hyp;

	ka_x = (double)ft_mod(first->x - second->x);
	ka_y = (double)ft_mod(first->y - second->y);
	hyp = ft_dsqrt((ka_x * ka_x) + (ka_y * ka_y));
	return (hyp);
}

static	double	get_rooms(char *name1, char *name2, t_nodes *nodes)
{
	t_nodes	*tmp1;
	t_nodes	*tmp2;

	while (nodes)
	{
		if (!ft_strcmp(name1, nodes->name))
			tmp1 = nodes;
		if (!ft_strcmp(name2, nodes->name))
			tmp2 = nodes;
		nodes = nodes->next;
	}
	return (get_len(tmp1, tmp2));
}

extern	void	find_len(t_links *links, t_nodes *nodes)
{
	while (links)
	{
		links->len = get_rooms(links->name1, links->name2, nodes);
		links = links->next;
	}
}
