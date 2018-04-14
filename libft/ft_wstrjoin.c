/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 09:23:01 by ybohusev          #+#    #+#             */
/*   Updated: 2018/03/06 09:23:03 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrjoin(wchar_t const *s1, wchar_t const *s2)
{
	int		k;
	int		i;
	wchar_t	*strcon;

	i = 0;
	k = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	strcon = (wchar_t*)malloc(sizeof(wchar_t) *
			(ft_wstrlen((wchar_t*)s1) + ft_wstrlen((wchar_t*)s2) + 1));
	if (strcon == NULL)
		return (NULL);
	while (s1[i])
		strcon[k++] = s1[i++];
	i = 0;
	while (s2[i])
		strcon[k++] = s2[i++];
	strcon[k] = '\0';
	return (strcon);
}
