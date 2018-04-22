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

static	int		is_rooms(t_data **data)
{
	int		rooms;
	int		start;
	int		end;

	rooms = 0;
	start = 0;
	end = 0;
	while (data && !is_link(data->str))
	{
		if (!ft_strcmp(data->str, "##start"))
			start++;
		if (!ft_strcmp(data->str, "##end"))
			end++;
		rooms++;
		data = data->next;
	}
	if (rooms == 0)
	{
		ft_putendl("\033[31mERROR:\033[37m ant farm must has at least 2 rooms!");
		ft_putstr("\tYour count of rooms: \033[33m\"");
		ft_putnbr(rooms);
		ft_putendl("\"\033[37m");
		exit(0);
	}
	if (end == 0 || end > 1)
	{
		ft_putendl("\033[31mERROR:\033[37m ant farm must has one and only one end room!");
		ft_putstr("\tYour count of end room: \033[33m\"");
		ft_putnbr(end);
		ft_putendl("\"\033[37m");
		exit(0);
	}
	if (start == 0 || start > 1)
	{
		ft_putendl("\033[31mERROR:\033[37m ant farm must has one and only one start room!");
		ft_putstr("\tYour count of start room: \033[33m\"");
		ft_putnbr(start);
		ft_putendl("\"\033[37m");
		exit(0);
	}
	return (data);
}

// static	void	is_links(t_data *data)
// {
// 	int		links;

// 	links = 0;
// 	while (data)
// 	{
// 		links++;
// 		data = data->next;
// 	}
// 	if (links == 0)
// 	{
// 		ft_putendl("\033[31mERROR:\033[37m ant farm must has at least 1 links!");
// 		ft_putstr("\tYour count of links: \033[33m\"");
// 		ft_putnbr(links);
// 		ft_putendl("\"\033[37m");
// 		exit(0);
// 	}
// }

static	int		is_data_empty(t_data *data)
{
	if (!data)
		return (NO_DATA);
	return (0);
}

extern	int		validation(t_data *data)
{
	int		err;

	err = 0;
	if ((err = is_data_empty(data)))
		return (err);
	if ((err = is_ants(&data)))
		return (err);
	if ((err = is_rooms(&data)));
	// is_links(data);
	return (0);
}
