   /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 16:32:23 by ybohusev          #+#    #+#             */
/*   Updated: 2018/04/22 16:32:24 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

extern	void	del_data(t_data *data)
{
	if (!data)
		return ;
	if (data->next)
		del_data(data->next);
	if (data->str)
	{
		free(data->str);
		data->str = NULL;
	}
	data = NULL;
}
