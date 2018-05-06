/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 13:00:14 by ybohusev          #+#    #+#             */
/*   Updated: 2018/04/23 13:00:15 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

static	int		check_name(char *name, t_data *data)
{
	int		count;
	int		flag;
	char	**tmp;

	count = 0;
	flag = 0;
	if (name[0] == 'L')
		return (INVALID_NAME);
	while (name[count])
	{
		if (name[count] == '-' || !ft_isprint(name[count]))
			return (INVALID_NAME);
		count++;
	}
	while (data && !is_link(data->str))
	{
		tmp = ft_strsplit(data->str, ' ');
		if (tmp[0] && !ft_strcmp(tmp[0], name))
			flag++;
		free_st_st(tmp);
		data = data->next;
	}
	if (flag > 1)
		return (INVALID_ROOMS);
	return (0);
}

static	int		check_coord(char *x, char *y)
{
	int		count;

	count = 0;
	while (x[count])
	{
		if (!ft_isdigit(x[count]))
			return (INVALID_COORDS);
		count++;
	}
	count = 0;
	while (y[count])
	{
		if (!ft_isdigit(y[count]))
			return (INVALID_COORDS);
		count++;
	}
	return (0);
}

extern	int		is_valid_room(char *str, t_data *data)
{
	char	**tmp;

	if (*str == 0)
		return (EMPTY_LINE);
	tmp = ft_strsplit(str, ' ');
	if (!tmp[1] || !tmp[2])
	{
		free_st_st(tmp);
		return (INVALID_COORDS);
	}
	if (check_name(tmp[0], data) || check_coord(tmp[1], tmp[2]))
	{
		free_st_st(tmp);
		return (INVALID_NAME);
	}
	free_st_st(tmp);
	return (0);
}
