/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:48:56 by ybohusev          #+#    #+#             */
/*   Updated: 2018/04/23 15:49:00 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static	void	free_st_st(char **str)
{
	int		count;

	count = 0;
	while (str[count])
	{
		free(str[count]);
		str[count] = NULL;
		count++;
	}
	free(str);
	str = NULL;
}

static	int		check_name(char *x, t_table *table)
{
	int		m;

	m = 0;
	while (table)
	{
		if (!ft_strcmp(x, table->name))
		{
			m = 1;
			return (0);
		}
		table = table->next;
	}
	return (INVALID_LINK);
}

extern	int		is_valid_link(t_data *data, t_table *table)
{
	char	**tmp;

	if (data->str == 0 || !is_link(data->str))
	{
		del_data(data);
		return (INVALID_LINK);
	}
	tmp = ft_strsplit(data->str, '-');
	if (!tmp[0] || !tmp[1])
	{
		del_data(data);
		free_st_st(tmp);
		return (INVALID_LINK);
	}
	if (check_name(tmp[0], table) || check_name(tmp[1], table))
	{
		del_data(data);
		free_st_st(tmp);
		return (INVALID_NAME);
	}
	free_st_st(tmp);
	return (0);
}
