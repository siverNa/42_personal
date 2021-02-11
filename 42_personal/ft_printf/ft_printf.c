/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:11:15 by sna               #+#    #+#             */
/*   Updated: 2021/02/11 17:01:01 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_type(va_list ap, t_form *form)
{
	int			len;
	char		type;

	len = 0;
	type = form->type;
	if (type == 'c')
		len = print_char(va_arg(ap, int), form);
	else if (type == '%')
		len = print_char('%', form);
	else if (type == 's')
		len = print_string(va_arg(ap, char *), form);
	else if (type == 'd' || type == 'i')
		len = print_number(va_arg(ap, int), form);
	else if (type == 'x' || type == 'X' || type == 'u')
		len = print_number(va_arg(ap, unsigned int), form);
	else if (type == 'p')
		len = print_number(va_arg(ap, unsigned long long), form);
	return (len);
}

void	check_width_and_prec(va_list ap, char *format, t_form *form, int i)
{
	if (ft_isdigit(format[i]))
	{
		if (!(form->flag & F_PREC))
			form->width = form->width * 10 + format[i] - '0';
		else
			form->prec = form->prec * 10 + format[i] - '0';
	}
	else if (format[i] == '*')
	{
		if (!(form->flag & F_PREC))
		{
			form->width = va_arg(ap, int);
			if (form->width < 0)
			{
				form->flag |= F_MINUS;
				form->width *= -1;
			}
		}
		else
			form->prec = va_arg(ap, int);
	}
}

void	check_form(va_list ap, char *format, t_form *form, int i)
{
	if (format[i] == '0' && !(form->flag & F_WIDTH) && !(form->flag & F_PREC))
		form->flag |= F_ZERO;
	else if (format[i] == '-')
		form->flag |= F_MINUS;
	else if (format[i] == '.')
	{
		form->flag |= F_PREC;
		form->prec = 0;
	}
	else if (ft_isdigit(format[i]) || format[i] == '*')
		check_width_and_prec(ap, format, form, i);
}

int		process_format(va_list ap, char *format)
{
	int			len;
	int			i;
	t_form		*form;

	i = 0;
	len = 0;
	if (!(form = malloc(sizeof(t_form) * 1)))
		return (-1);
	while (format[i] != '\0')
	{
		while (format[i] != '%' && format[i] != '\0')
			len += ft_putchar(format[i++]);
		if (format[i] == '%')
		{
			init_form(form);
			while (format[++i] != '\0' && !(ft_strchr(TYPE, format[i])))
				check_form(ap, format, form, i);
			form->type = format[i++];
			if ((form->flag & F_MINUS || form->prec > -1) && form->type != '%')
				form->flag &= (~F_ZERO);
			len += print_type(ap, form);
		}
	}
	free(form);
	return (len);
}

int		ft_printf(const char *format, ...)
{
	int			len;
	va_list		ap;

	va_start(ap, format);
	len = process_format(ap, (char *)format);
	va_end(ap);
	return (len);
}
