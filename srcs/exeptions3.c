/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exeptions3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 17:09:53 by ybohusev          #+#    #+#             */
/*   Updated: 2018/05/03 17:09:54 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	no_data(void)
{
	ft_putstr("\033[34musage:\033[39m ./lem-in < ");
	ft_putendl("[\033[33minput data\033[39m]");
	ft_putendl("\033[35minput data must be in following format:\033[39m");
	ft_putendl("number of ants.\nthe rooms.\nthe links.");
	exit(0);
}

void	empty_line(void)
{
	ft_putendl("\033[31mERROR:\033[39m empty line in ants or room definition!");
	exit(0);
}
