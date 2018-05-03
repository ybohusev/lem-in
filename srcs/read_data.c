/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 16:03:02 by ybohusev          #+#    #+#             */
/*   Updated: 2018/04/21 16:03:03 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	t_data	*get_data_list(char *line, t_data *data)
{
	t_data	*tmp;
	t_data	*t;

	tmp = (t_data*)malloc(sizeof(t_data) * 1);
	tmp->str = ft_strdup(line);
	tmp->is_err = 0;
	tmp->next = NULL;
	if (!data)
	{
		data = tmp;
		data->prev = NULL;
		return (data);
	}
	t = data;
	while (data->next)
		data = data->next;
	data->next = tmp;
	data->next->prev = data;
	return (t);
}

extern	t_data	*read_data(void)
{
	t_data	*data;
	char	*line;

	data = NULL;
	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		data = get_data_list(line, data);
		free(line);
	}
	return (data);
}
