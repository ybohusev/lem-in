/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_links.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 15:34:29 by ybohusev          #+#    #+#             */
/*   Updated: 2018/05/11 15:34:30 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	int		inv_comm(t_data *data)
{
	if (!data)
		return (NO_LINKS);
	if (!ft_strcmp(data->prev->str, "##start"))
		return (INVALID_START);
	if (!ft_strcmp(data->prev->str, "##end"))
		return (INVALID_END);
	return (0);
}

extern	int		is_links(t_data *data, t_data *tmp)
{
	int		links;
	char	hash;
	int		err;

	links = 0;
	err = 0;
	if ((err = inv_comm(data)))
		return (err);
	while (data)
	{
		hash = data->str[0];
		if (hash != '#' && !is_valid_link(data, tmp))
			links++;
		else if (hash != '#' && (err = INVALID_LINK))
			break ;
		data = data->next;
	}
	if (links == 0)
		return (NO_LINKS);
	else if (err == INVALID_LINK && (data->is_err = 1))
		return (err);
	return (0);
}
