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

static	t_table	*add_name(char *name, t_table *table)
{
	t_table	*tmp;
	t_table	*t;

	tmp = (t_table*)malloc(sizeof(t_table) * 1);
	tmp->name = ft_strdup(name);
	tmp->next = NULL;
	if (!table)
	{
		table = tmp;
		return (table);
	}
	t = table;
	while (table->next)
		table = table->next;
	table->next = tmp;
	return (t);
}

static	int		check_name(char *name, t_table *table)
{
	int		count;

	count = 0;
	if (name[0] == 'L')
		return (INVALID_NAME);
	while (name[count])
	{
		if (name[count] == '-' || !ft_isprint(name[count]))
			return (INVALID_NAME);
		count++;
	}
	while (table)
	{
		if (!ft_strcmp(table->name, name))
			return (INVALID_NAME);
		table = table->next;
	}
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

extern	int		is_valid_room(char *str, t_table **table)
{
	char	**tmp;

	if (*str == 0)
	{
		// del_table(*table);
		return (EMPTY_LINE);
	}
	tmp = ft_strsplit(str, ' ');
	if (!tmp[1] || ! tmp[2])
	{
		free_st_st(tmp);
		// del_table(*table);
		return (INVALID_COORDS);
	}
	if (check_name(tmp[0], *table) || check_coord(tmp[1], tmp[2]))
	{
		free_st_st(tmp);
		// del_table(*table);
		return (INVALID_NAME);
	}
	*table = add_name(tmp[0], *table);
	free_st_st(tmp);
	return (0);
}
