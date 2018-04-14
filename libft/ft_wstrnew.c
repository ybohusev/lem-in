/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 09:23:36 by ybohusev          #+#    #+#             */
/*   Updated: 2018/03/06 09:23:38 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrnew(size_t size)
{
	wchar_t	*newstr;
	size_t	i;

	i = 0;
	newstr = (wchar_t*)malloc(sizeof(wchar_t) * (size + 1));
	if (newstr == NULL)
		return (NULL);
	while (i <= size)
		newstr[i++] = '\0';
	return (newstr);
}
