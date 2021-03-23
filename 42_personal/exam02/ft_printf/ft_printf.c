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

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

char	*ft_strchr(const char *s, int c)
{
	size_t			i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c && c == 0)
		return ((char *)s + i);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t			i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_putstr(char *s)
{
	int				i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	if (dest == 0 && src == 0)
		return (0);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char 			*join_s;
	size_t			s1_len;
	size_t			s2_len;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(join_s = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (NULL);
	ft_memcpy(join_s, s1, s1_len);
	ft_memcpy(join_s + s1_len, s2, s2_len);
	join_s[s1_len + s2_len] = 0;
	return (join_s);
}

int		put_minus(t_form *form, char **n_buff)
{
	int				nbr_len;
	char			*temp;

	nbr_len = 0;
	if ((form->type == 'd') && (form->nbr_sign == -1))
	{
		temp = ft_strjoin("-", *n_buff);
		free(*n_buff);
		*n_buff = temp;
		nbr_len = 1;
	}
	return (nbr_len);
}

void	init_form(t_form *form)
{
	form->flag &= (~F_PREC);
	form->width = 0;
	form->prec = -1;
	form->type = 0;
	form->nbr_base = 10;
	form->nbr_sign = 1;
}

int		ft_nbrlen(unsigned long long nbr, t_form *form)
{
	int 			i;

	i = 0;
	if ((nbr == 0) && (form->prec != 0))
		return (1);
	while (nbr)
	{
		i++;
		nbr = nbr / form->nbr_base;
	}
	return (i);
}

char	*ft_baseset(char type)
{
	if (type == 'd')
		return ("0123456789");
	else if (type == 'x')
		return ("0123456789abcdef");
	return (0);
}

int		put_str_width(char **buff, t_form *form)
{
	int				i;
	char			*width;
	char			*temp;

	if (form->width <= (int)ft_strlen(*buff))
		return ((int)ft_strlen(*buff));
	if (!(width = (char *)malloc(sizeof(char) *
					(form->width - ft_strlen(*buff) + 1))))
		return (0);
	i = 0;
	while ((size_t)i < form->width - ft_strlen(*buff))
	{
		width[i] = ' ';
		i++;
	}
	width[i] = '\0';
	temp = ft_strjoin(width, *buff);
	free(width);
	free(*buff);
	*buff = temp;
	return (form->width);
}

int		put_str_prec(unsigned long long nbr, t_form *form, char **n_buff)
{
	int				nbr_len;
	int				prec_len;
	int				i;

	nbr_len = ft_nbrlen(nbr, form);
	prec_len = (form->prec > nbr_len) ? form->prec : nbr_len;
	if (!(*n_buff = (char *)malloc(sizeof(char) * (prec_len + 1))))
		return (0);
	(*n_buff)[prec_len] = '\0';
	i = 0;
	while (nbr_len + i < prec_len)
	{
		(*n_buff)[i] = '0';
		i++;
	}
	i = 1;
	if (nbr == 0 && form->prec != 0)
		(*n_buff)[prec_len - i] = '0';
	while (nbr)
	{
		(*n_buff)[prec_len - i] = ft_baseset(form->type)[nbr % form->nbr_base];
		nbr = nbr / form->nbr_base;
		i++;
	}
	return (nbr_len);
}

int		print_number(unsigned long long nbr, t_form *form)
{
	int				nbr_len;
	int				s_len;
	char			*nbr_buff;

	if (form->type == 'x')
		form->nbr_base = 16;
	if (form->type == 'd' && (int)nbr < 0)
	{
		form->nbr_sign = -1;
		nbr = nbr * (-1);
	}
	nbr_len = put_str_prec(nbr, form, &nbr_buff);
	nbr_len += put_minus(form, &nbr_buff);
	s_len = put_str_width(&nbr_buff, form);
	ft_putstr(nbr_buff);
	free(nbr_buff);
	return (s_len);
}

char	*str_to_buff(char *str, int prec_len, int s_len)
{
	int				i;
	char			*buff;

	prec_len = (prec_len < s_len ? prec_len : s_len);
	if (!(buff = (char *)malloc(sizeof(char) * (prec_len + 1))))
		return (NULL);
	i = 0;
	while (i < prec_len)
	{
		buff[i] = str[i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}

int		print_string(char *str, t_form *form)
{
	int				len;
	char			*buff;

	len = 0;
	if (str == NULL)
		str = "(null)";
	if (!(form->flag & F_PREC) || (size_t)form->prec > ft_strlen(str))
		form->prec = ft_strlen(str);
	buff = str_to_buff(str, form->prec, ft_strlen(str));
	len = put_str_width(&buff, form);
	ft_putstr(buff);
	free(buff);
	return (len);
}

int		print_type(va_list ap, t_form *form)
{
	int				len;
	char			type;

	len = 0;
	type = form->type;
	if (type == 's')
		len = print_string(va_arg(ap, char *), form);
	else if (type == 'd')
		len = print_number(va_arg(ap, int), form);
	else if (type == 'x')
		len = print_number(va_arg(ap, unsigned int), form);
	return (len);
}

void	check_width_and_prec(char *format, t_form *form, int i)
{
	if (ft_isdigit(format[i]))
	{
		if (!(form->flag & F_PREC))
			form->width = form->width * 10 + format[i] - '0';
		else
			form->prec = form->prec * 10 + format[i] - '0';
	}
}

void	check_form(char *format, t_form *form, int i)
{
	if (format[i] == '.')
	{
		form->flag |= F_PREC;
		form->prec = 0;
	}
	else if (ft_isdigit(format[i]))
		check_width_and_prec(format, form, i);
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
			while (format[++i] != '\0' && !(ft_strchr(TYPE, format[i])))
				check_form(format, form, i);
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
