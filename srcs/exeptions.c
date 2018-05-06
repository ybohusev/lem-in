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

#include "lem_in.h"

static	void	invalid_coords(void)
{
	ft_putendl("\033[31mERROR:\033[39minvalid room coordinates!");
	exit(0);
}

static	void	no_links(void)
{
	ft_putendl("\033[31mERROR:\033[39m ant's farm must has at least 1 link!");
	exit(0);
}

static	void	invalid_link(void)
{
	ft_putendl("\033[34mWARNING:\033[39m invalid link definition!");
	ft_putendl("current and the following lines will be ignored");
}

static	void	no_path(void)
{
	ft_putstr("\033[31mERROR:\033[39m ant's farm ");
	ft_putendl("has no path from start to end!");
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
	else if (err == NO_ROOMS)
		no_rooms();
	else if (err == INVALID_END)
		invalid_end();
	else if (err == INVALID_START)
		invalid_start();
	else if (err == INVALID_NAME)
		invalid_name();
	else if (err == INVALID_COORDS)
		invalid_coords();
	else if (err == NO_LINKS)
		no_links();
	else if (err == INVALID_LINK)
		invalid_link();
	else if (err == NO_PATH)
		no_path();
}
