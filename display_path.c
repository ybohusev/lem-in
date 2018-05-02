/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:57:29 by ybohusev          #+#    #+#             */
/*   Updated: 2018/04/26 14:00:46 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static	void	display_ants(t_path *path)
{
	int		id_ant;
	int		count;
	t_path	*begin;
	t_path	*end;
	t_path	*current;

	begin = path;
	end = path->next;
	end->ants = 1;
	count = 1;
	path->ants--;
	while (begin)
	{
		id_ant = count;
		current = end;
		while (current != begin)
		{
			printf("L%d-%s ", id_ant, current->name);
			current = current->prev;
			id_ant++;
		}
		if (begin->next)
			printf("\n");
		if (path->ants <= 0)
			begin = begin->next;
		if (end->next)
			end = end->next;
		else
			count++;
		if (path->ants > 0)
			path->ants--;
	}
}

extern	void	display_path(t_path *path, t_data *data)
{
	while (data)
	{
		ft_putendl(data->str);
		data = data->next;
	}
	ft_putchar('\n');
	display_ants(path);
}
