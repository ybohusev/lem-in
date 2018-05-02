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
	// system("leaks lem-in");
	exit(0);
}

static	void	empty_line(void)
{
	ft_putendl("\033[31mERROR:\033[37m empty line in ants or room definition!");
	// system("leaks lem-in");
	exit(0);
}

static	void	no_ants(void)
{
	ft_putstr("\033[31mERROR:\033[37m first string must be the number of ants!");
	ft_putendl(" (none zero positive integer)");
	// system("leaks lem-in");
	exit(0);
}

static	void	no_rooms(void)
{
	ft_putendl("\033[31mERROR:\033[37m ant's farm must has at least 2 rooms!");
	// system("leaks lem-in");
	exit(0);
}

static	void	invalid_end(void)
{
	ft_putendl("\033[31mERROR:\033[37m ant's farm must has one and only one end room!");
	// system("leaks lem-in");
	exit(0);
}

static	void	invalid_start(void)
{
	ft_putendl("\033[31mERROR:\033[37m ant's farm must has one and only one start room!");
	system("leaks lem-in");
	exit(0);
}

static	void	invalid_name(void)
{
	ft_putendl("\033[31mERROR:\033[37m invalid room name!");
	// system("leaks lem-in");
	exit(0);
}

static	void	invalid_coords(void)
{
	ft_putendl("\033[31mERROR:\033[37m invalid room coordinates!");
	// system("leaks lem-in");
	exit(0);
}

static	void	no_links(void)
{
	ft_putendl("\033[31mERROR:\033[37m ant's farm must has at least 1 link!");
	// system("leaks lem-in");
	exit(0);
}

static	void	invalid_link(void)
{
	ft_putendl("\033[34mWARNING:\033[37m invalid link definition!");
	ft_putendl("current and the following lines will be ignored");
}

static	void	no_path(void)
{
	ft_putendl("\033[31mERROR:\033[37m ant's farm has no path from start to end!");
	// system("leaks lem-in");
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
