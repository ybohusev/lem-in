/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 10:19:58 by ybohusev          #+#    #+#             */
/*   Updated: 2018/02/05 10:20:00 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

static	int		mem_size(uintmax_t n, int base)
{
	int		i;

	i = 1;
	while (n / base != 0)
	{
		i++;
		n = n / base;
	}
	return (i);
}

extern	char	*ft_itoa_base(uintmax_t n, int base)
{
	char				*str;
	int					i;

	i = mem_size(n, base);
	str = (char*)malloc(i + 1);
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	while (--i >= 0)
	{
		if (n % base >= 10)
			str[i] = n % base - 10 + 97;
		else
			str[i] = n % base + 48;
		n = n / base;
	}
	return (str);
}
