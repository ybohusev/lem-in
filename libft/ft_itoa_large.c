/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:54:12 by ybohusev          #+#    #+#             */
/*   Updated: 2017/11/06 17:54:17 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	int		mem_size(intmax_t n)
{
	int			i;
	intmax_t	temp;

	temp = n;
	i = 1;
	while (temp / 10 != 0)
	{
		i++;
		temp = temp / 10;
	}
	if (n < 0)
		return (i + 1);
	return (i);
}

extern	char	*ft_itoa_large(intmax_t n)
{
	uintmax_t		temp;
	char			*str;
	int				i;

	i = mem_size(n);
	if (n < 0)
		temp = n * -1;
	else
		temp = n;
	str = (char*)malloc(i + 1);
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	while (--i >= 0)
	{
		str[i] = temp % 10 + 48;
		temp = temp / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
