/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 12:14:00 by sna               #+#    #+#             */
/*   Updated: 2020/10/31 12:02:51 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_print(unsigned char c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	return (0);
}

void	write_hex(unsigned char c)
{
	c = c + '0';
	if (c > '9')
		c = c + 39;
	write(1, &c, 1);
}

void	print_hex(unsigned char c)
{
	write(1, "\\", 1);
	write_hex(c / 16);
	write_hex(c % 16);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!check_print(str[i]))
			print_hex(str[i]);
		else
			write(1, &str[i], 1);
		i++;
	}
}
