/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:06:05 by sna               #+#    #+#             */
/*   Updated: 2021/02/11 18:07:17 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_width_len(t_form *form, int f_len)
{
	int		len;

	len = 0;
	while (f_len < form->width)
	{
		if (form->flag & F_ZERO)
			ft_putchar('0');
		else
			ft_putchar(' ');
		f_len++;
		len++;
	}
	return (len);
}

int		print_char(int c, t_form *form)
{
	int		len;

	len = 0;
	if (form->type == '%' && (form->flag & F_MINUS))
		form->flag &= (~F_ZERO);
	if (form->flag & F_MINUS)
		len += ft_putchar(c);
	len += print_width_len(form, 1);
	if (!(form->flag & F_MINUS))
		len += ft_putchar(c);
	return (len);
}
