/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 16:24:54 by ybohusev          #+#    #+#             */
/*   Updated: 2018/04/21 16:24:56 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static	int		is_ants(t_data **data)
{
	char	*line;

	line = (*data)->str;
	if (!line || line[0] == 0)
		return (EMPTY_LINE);
	while (*line)
	{
		if (!ft_isdigit(*line))
			return (NO_ANTS);
		line++;
	}
	if (ft_atoi((*data)->str) <= 0)
		return (NO_ANTS);
	(*data) = (*data)->next;
	return (0);
}

static	int		is_rooms(t_data **data, t_table **table)
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
		if (!ft_strcmp((*data)->str, "##start"))
			start++;
		else if (!ft_strcmp((*data)->str, "##end"))
			end++;
		else if ((*data)->str[0] != '#' && !(code = is_valid_room((*data)->str, table)))
			rooms++;
		else if ((*data)->str[0] != '#')
			return (code);
		*data = (*data)->next;
	}
	if (rooms == 0 || rooms == 1)
		return (NO_ROOMS);
	if (end == 0 || end > 1)
		return (INVALID_END);
	if (start == 0 || start > 1)
		return (INVALID_START);
	return (0);
}

static	int		is_links(t_data *data, t_table *table)
{
	int		links;
	char	hash;
	int		err;

	links = 0;
	err = 0;
	while (data)
	{
		hash = data->str[0];
		if (hash != '#' && !is_valid_link(data, table))
			links++;
		else if (hash != '#')
		{
			err = INVALID_LINK;
			break ;
		}
		data = data->next;
	}
	// del_table(table);
	if (links == 0)
		return (NO_LINKS);
	else if (err == INVALID_LINK)
		return (err);
	return (0);
}

static	int		is_data_empty(t_data *data)
{
	if (!data)
		return (NO_DATA);
	return (0);
}

extern	int		validation(t_data *data)
{
	int		err;
	t_table	*table;

	err = 0;
	table = NULL;
	if ((err = is_data_empty(data)))
		return (err);
	if ((err = is_ants(&data)))
		return (err);
	if ((err = is_rooms(&data, &table)))
		return (err);
	if ((err = is_links(data, table)))
		return (err);
	return (0);
}
