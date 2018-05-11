/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rooms.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 15:37:12 by ybohusev          #+#    #+#             */
/*   Updated: 2018/05/11 15:37:13 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	int		return_is_rooms(int rooms, int end, int start)
{
	if (rooms == 0 || rooms == 1)
		return (NO_ROOMS);
	if (end == 0 || end > 1)
		return (INVALID_END);
	if (start == 0 || start > 1)
		return (INVALID_START);
	return (0);
}

static	int		is_start(t_data *data)
{
	if (!ft_strcmp(data->str, "##start"))
	{
		if (data->next && ft_strcmp(data->next->str, "##end"))
			return (1);
	}
	return (0);
}

static	int		is_end(t_data *data)
{
	if (!ft_strcmp(data->str, "##end"))
	{
		if (data->next && ft_strcmp(data->next->str, "##start"))
			return (1);
	}
	return (0);
}

extern	int		is_rooms(t_data **data, t_data *tmp)
{
	int		rooms;
	int		start;
	int		end;
	int		code;

	rooms = 0;
	start = 0;
	end = 0;
	code = 0;
	while (*data && !is_link((*data)->str))
	{
		start += is_start(*data);
		end += is_end(*data);
		if ((*data)->str[0] != '#' &&
				!(code = is_valid_room((*data)->str, tmp)))
			rooms++;
		else if ((*data)->str[0] != '#')
			return (code);
		*data = (*data)->next;
	}
	return (return_is_rooms(rooms, end, start));
}
