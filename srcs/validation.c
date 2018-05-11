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

#include "lem_in.h"

static	int		is_ants(t_data **data)
{
	char	*line;

	line = (*data)->str;
	if (*line == '+')
		line++;
	if (ft_strlen(line) > 10)
		return (NO_ANTS);
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
	if ((*data)->next)
		(*data) = (*data)->next;
	else
		return (NO_ROOMS);
	return (0);
}

extern	int		validation(t_data *data)
{
	int		err;
	t_data	*tmp;

	err = 0;
	if (!data)
		return (NO_DATA);
	if ((err = is_ants(&data)))
		return (err);
	tmp = data;
	if ((err = is_rooms(&data, tmp)))
		return (err);
	if ((err = is_links(data, tmp)))
		return (err);
	return (0);
}
