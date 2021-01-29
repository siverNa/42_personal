#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else
	{
		if (n >= 10)
			ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
}

int practice_printf(const char *format, ...)
{
	va_list ap;
	int		len;
	char	c_var;

	len = 0;
	va_start(ap, format);
	while (*format && format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				c_var = va_arg(ap, int);
				write(1, &c_var, 1);
				len++;
			}
			else if (*format == 'd' || *format == 'i')
			{
				c_var = va_arg(ap, int);
				ft_putnbr(c_var);
				len++;
			}
			if (format != NULL)
				format++;
		}
		else
		{
			write(1, format, 1);
			format++;
			len++;
		}
	}
	va_end(ap);
	return (len);
}

int main(void)
{
	printf("printf value : %d\n", 20);
	practice_printf("practice_printf value : %d\n", 20);

	return (0);
}
