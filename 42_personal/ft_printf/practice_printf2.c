#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

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
				write(1, &c_var, 1);
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
	printf("printf value : %d\n", 5);
	practice_printf("practice_printf value : %d\n", 5);

	return (0);
}
