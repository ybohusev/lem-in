/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 09:23:26 by ybohusev          #+#    #+#             */
/*   Updated: 2018/03/06 09:23:29 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_wstrsize(wchar_t *wstr)
{
	size_t	i;
	size_t	prt;

	i = 0;
	prt = 0;
	if (wstr != NULL)
	{
		while (wstr[i])
		{
			prt += ft_count_octets(wstr[i]);
			i++;
		}
	}
	return (prt);
}
