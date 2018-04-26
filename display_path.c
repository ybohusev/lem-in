/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:57:29 by ybohusev          #+#    #+#             */
/*   Updated: 2018/04/26 14:00:46 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

extern	void	display_path(t_path *path, t_data *data)
{
	while (data)
	{
		ft_putendl(data->str);
		data = data->next;
	}
	ft_putchar('\n');
	path = path->next;
}
