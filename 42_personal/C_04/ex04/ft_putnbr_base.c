/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:05:22 by sna               #+#    #+#             */
/*   Updated: 2020/11/02 10:39:18 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		rec(int nbr, char *base, int len)
{
	if (nbr == 0)
		return ;
	rec(nbr / len, base, len);
	write(1, &base[nbr % len], 1);
}

int			base_len(char *base)
{
	char	check[256];
	int		i;
	int		len;
	char	c;

	i = 0;
	while (i <= 255)
		check[i++] = 0;
	len = 0;
	while (base[len] != '\0')
	{
		c = base[len];
		if (check[(int)c] == 1)
			return (0);
		if (c == '+' || c == '-')
			return (0);
		if (c == ' ')
			return (0);
		if (c >= '\t' && c <= '\r')
			return (0);
		check[(int)c] = 1;
		len++;
	}
	return (len);
}

void		ft_putnbr_base(int nbr, char *base)
{
	int		len;

	len = base_len(base);
	if (len == 0 || len == 1)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		rec(-(nbr / len), base, len);
		write(1, &base[nbr % len * (-1)], 1);
	}
	else
	{
		rec(nbr / len, base, len);
		write(1, &base[nbr % len], 1);
	}
}
