/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:30:31 by ybohusev          #+#    #+#             */
/*   Updated: 2018/04/23 14:30:32 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

extern	void	del_table(t_table *table)
{
	if (!table)
		return ;
	if (table->next)
		del_table(table->next);
	if (table->name)
	{
		free(table->name);
		table->name = NULL;
	}
	free(table);
	table = NULL;
}
