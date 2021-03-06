#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

#define F_PREC		1
#define TYPE		"sdx"

typedef struct s_form
{
	unsigned int	flag;
	int				width;
	int				prec;
	int				nbr_sign;
	int				nbr_base;
	char			type;
} t_form;

int		print_type(va_list ap, t_form *form)
{
	int				len;
	char			type;

	len = 0;
	type = form->type;
	if (type == 's')
		len = print_string(va_arg(ap, char *), format);
	else if (type == 'd')
		len = print_number(va_arg(ap, int), formet);
	else if (type == 'x')
		len = print_number(va_arg(ap, unsigned int), format);
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
}

void	check_form(va_list ap, char *format, t_form *form, int i)
{
	if (format[i] == '.')
	{
		form->flag |= F_PREC;
		form->prec = 0;
	}
	else if (ft_isdigit(format[i]))
		check_width_and_prec(ap, format, form, i);
}

int		process_format(va_list ap, char *format)
{
	int				len;
	int				i;
	t_form			*form;

	len = 0;
	i = 0;
	if (!(form = malloc(sizeof(t_form) * 1)))
		return (-1);
	while (format[i] != '\0')
	{
		while (format[i] != '%' && format[i] != '\0')
			len += ft_putchar(format[i++]);
		if (format[i] == '%')
		{
			init_form(form);
			while (format[++i] != '\0' && ft_strchr(TYPE, format[i]))
				check_form(ap, format, form, i);
			form->type = format[i++];
			len += print_type(ap, form);
		}
	}
	free(form);
	return (len);
}

int		ft_printf(const char *format, ...)
{
	int				len;
	va_list 		ap;

	va_start(ap, format);
	len = process_format(ap, (char *)format);
	va_end(ap);
	return (len);
}
