/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exeptions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 16:16:46 by ybohusev          #+#    #+#             */
/*   Updated: 2018/04/22 16:16:46 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static	void	no_data(void)
{
	ft_putendl("\033[34musage:\033[37m ./lem-in < [\033[33minput data\033[37m]");
	ft_putendl("\033[35minput data must be in following format:\033[37m");
	ft_putendl("number of ants.\nthe rooms.\nthe links.");
	exit(0);
}

static	void	empty_line(void)
{
	ft_putendl("\033[31mERROR:\033[37m empty line in ants or room definition!");
	exit(0);
}

static	void	no_ants(void)
{
	ft_putstr("\033[31mERROR:\033[37m first string must be the number of ants!");
	ft_putendl(" (none zero positive integer)");
	exit(0);
}

extern	void	exeptions(int err)
{
	if (err == NO_DATA)
		no_data();
	else if (err == EMPTY_LINE)
		empty_line();
	else if (err == NO_ANTS)
		no_ants();
}
