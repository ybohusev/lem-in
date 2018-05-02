/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 13:47:47 by ybohusev          #+#    #+#             */
/*   Updated: 2018/05/02 13:51:33 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

extern	void	del_path(t_path *path)
{
	if (!path)
		return ;
	if (path->next)
		del_path(path->next);
	if (path->name)
	{
		free(path->name);
		path->name = NULL;
	}
	free(path);
	path = NULL;
}
