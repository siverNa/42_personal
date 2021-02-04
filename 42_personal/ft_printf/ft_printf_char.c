/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:06:05 by sna               #+#    #+#             */
/*   Updated: 2021/02/04 19:04:41 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_char(int c, t_form *form)
{
	int		len;

	len = 0;
	if (form->type == '%' && (form->flag & F_MINUS))
		form->flag &= (~F_ZERO);
	if (form->flag & F_MINUS)
		len += ft_putchar(c);
	len += print_width(form->width, 1, form->flag);
	if (!(form->flag & F_MINUS))
		len += ft_putchar(c);
	return (len);
}

int		print_width(int width, int f_len, int flag)
{
	int		len;

	len = 0;
	while (f_len < width)
	{
		if (flag & F_ZERO)
			ft_putchar('0');
		else
			ft_putchar(' ');
		f_len++;
		len++;
	}
	return (len);
}
