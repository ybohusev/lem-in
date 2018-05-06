/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exeptions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 17:04:38 by ybohusev          #+#    #+#             */
/*   Updated: 2018/05/03 17:04:39 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	no_ants(void)
{
	ft_putstr("\033[31mERROR:\033[39m first string ");
	ft_putstr("must be the number of ants!");
	ft_putendl(" (none zero positive integer)");
	exit(0);
}

void	no_rooms(void)
{
	ft_putendl("\033[31mERROR:\033[39m ant's farm must has at least 2 rooms!");
	exit(0);
}

void	invalid_end(void)
{
	ft_putstr("\033[31mERROR:\033[39m ant's farm must has ");
	ft_putendl("one and only one end room!");
	exit(0);
}

void	invalid_start(void)
{
	ft_putstr("\033[31mERROR:\033[39m ant's farm must has ");
	ft_putendl("one and only one start room!");
	exit(0);
}

void	invalid_name(void)
{
	ft_putendl("\033[31mERROR:\033[39m invalid room name!");
	exit(0);
}
