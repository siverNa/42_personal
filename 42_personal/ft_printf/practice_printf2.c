#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "./libft/libft.h"

int		print_char(int c)
{
	int		len;

	len = 0;

	len += ft_putchar(c);

	return (len);
}

int		process_format(va_list ap, char *format)
{
	int		len;
	int		i;
	//int		width;

	i = 0;
	len = 0;
	//width = 0;
	while (format[i] != '\0')
	{
		while (format[i] != '%' && format[i] != '\0')
			len += ft_putchar(format[i++]);
		if (format[i] == '%')
		{
			//while (format[++i] != '\0' && !(ft_strchr("cspdiuxX%", format[i])))
			i++;
			if (format[i] == 'c') //서식 지정자가 'c' 라면 문자하나 출력
			{
				len += print_char(va_arg(ap, int));
			}
			else if (format[i] == '%') // '%' 라면 %만 출력하도록 설정
				len += print_char('%');
		}
	}

	return (len);
}

int		practice_printf(const char *format, ...)
{
	va_list ap;
	int		len;

	len = 0;
	va_start(ap, format);

	len = process_format(ap, (char *)format);
	va_end(ap);
	return (len);
}

int main(void)
{
	printf("printf value : %%\n");
	practice_printf("practice_printf value : %%\n");
	
	printf("printf value : %c\n", 'a');
	practice_printf("practice_printf value : %c\n", 'a');

	return (0);
}
