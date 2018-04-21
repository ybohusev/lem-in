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

static	void	is_ants(t_data *data)
{
	char	*line;

	line = data->str;
	while (*line)
	{
		if (!ft_isdigit(*line))
		{
			ft_putendl("\033[31mERROR:\033[37m first string must be the number of ants!");
			ft_putstr("\tYour string: \033[33m\"");
			ft_putstr(data->str);
			ft_putendl("\"\033[37m");
			exit(0);
		}
		line++;
	}
}

static	void	check_rooms(t_data *data)
{
	while (data && !is_link(data->str))
	{
		
		data = data->next;
	}
}

extern	void	validation(t_data *data)
{
	if (!data)
	{
		ft_putendl("\033[34musage:\033[37m ./lem-in < [\033[33minput data\033[37m]");
		ft_putendl("input data must be in following format:");
		ft_putendl("\033[35mnumber of ants\nthe rooms\nthe links\033[37m");
		exit(0);
	}
	is_ants(data);
	data = data->next;
	check_rooms(data);
}
