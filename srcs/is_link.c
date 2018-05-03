/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_link.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 17:23:34 by ybohusev          #+#    #+#             */
/*   Updated: 2018/04/21 17:23:37 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

extern	int	is_link(char *str)
{
	int		hyphen;
	int		space;

	hyphen = 0;
	space = 0;
	while (*str)
	{
		if (*str == ' ')
			space++;
		if (*str == '-')
			hyphen++;
		str++;
	}
	if (hyphen == 1 && !space)
		return (1);
	return (0);
}
