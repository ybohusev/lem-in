/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_octets.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 09:43:25 by ybohusev          #+#    #+#             */
/*   Updated: 2018/02/16 09:43:28 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_octets(unsigned int a)
{
	int				bits;

	bits = (int)ft_strlen(ft_itoa_base(a, 2));
	if (bits <= 7)
		return (1);
	else if (bits <= 11)
		return (2);
	else if (bits <= 16)
		return (3);
	else if (bits > 16)
		return (4);
	return (0);
}
