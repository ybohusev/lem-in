/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 09:42:31 by ybohusev          #+#    #+#             */
/*   Updated: 2018/02/16 09:42:34 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	mas1(unsigned int a)
{
	unsigned char	ch;

	ch = a;
	write(1, &ch, 1);
}

static	void	mas2(unsigned int a, unsigned int mask)
{
	unsigned char	ch1;
	unsigned char	ch2;
	unsigned char	ch;

	ch2 = (a << 26) >> 26;
	ch1 = ((a >> 6) << 27) >> 27;
	ch = (mask >> 8) | ch1;
	write(1, &ch, 1);
	ch = (mask << 24) >> 24 | ch2;
	write(1, &ch, 1);
}

static	void	mas3(unsigned int a, unsigned int mask)
{
	unsigned char	ch1;
	unsigned char	ch2;
	unsigned char	ch3;
	unsigned char	ch;

	ch3 = (a << 26) >> 26;
	ch2 = ((a >> 6) << 26) >> 26;
	ch1 = ((a >> 12) << 28) >> 28;
	ch = (mask >> 16) | ch1;
	write(1, &ch, 1);
	ch = (mask << 16) >> 24 | ch2;
	write(1, &ch, 1);
	ch = (mask << 24) >> 24 | ch3;
	write(1, &ch, 1);
}

static	void	mas4(unsigned int a, unsigned int mask)
{
	unsigned char	ch1;
	unsigned char	ch2;
	unsigned char	ch3;
	unsigned char	ch4;
	unsigned char	ch;

	ch4 = (a << 26) >> 26;
	ch3 = ((a >> 6) << 26) >> 26;
	ch2 = ((a >> 12) << 26) >> 26;
	ch1 = ((a >> 18) << 29) >> 29;
	ch = (mask >> 24) | ch1;
	write(1, &ch, 1);
	ch = (mask << 8) >> 24 | ch2;
	write(1, &ch, 1);
	ch = (mask << 16) >> 24 | ch3;
	write(1, &ch, 1);
	ch = (mask << 24) >> 24 | ch4;
	write(1, &ch, 1);
}

extern	int		ft_putwchar(unsigned int a)
{
	int				octets;

	octets = ft_count_octets(a);
	if (octets == 1)
		mas1(a);
	else if (octets == 2)
		mas2(a, 49280);
	else if (octets == 3)
		mas3(a, 14712960);
	else if (octets == 4)
		mas4(a, 4034953344);
	return (octets);
}
