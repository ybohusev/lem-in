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

static	int		check_name(char *x, t_data *tmp)
{
	char	**tmp1;

	while (tmp && !is_link(tmp->str))
	{
		tmp1 = ft_strsplit(tmp->str, ' ');
		if (tmp1[0] && !ft_strcmp(tmp1[0], x))
		{
			free_st_st(tmp1);
			return (0);
		}
		free_st_st(tmp1);
		tmp = tmp->next;
	}
	return (INVALID_LINK);
}

extern	int		is_valid_link(t_data *data, t_data *tmp1)
{
	char	**tmp;

	if (data->str == 0 || !is_link(data->str))
		return (INVALID_LINK);
	tmp = ft_strsplit(data->str, '-');
	if (!tmp[0] || !tmp[1])
	{
		free_st_st(tmp);
		return (INVALID_LINK);
	}
	if (check_name(tmp[0], tmp1) || check_name(tmp[1], tmp1))
	{
		free_st_st(tmp);
		return (INVALID_NAME);
	}
	free_st_st(tmp);
	return (0);
}
