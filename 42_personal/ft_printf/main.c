#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int a;
	int b;

	printf("   printf value is : %c\n", 'a');
	ft_printf("ft_printf value is : %c\n", 'a');
	
	printf("   printf value is : %6c\n", 'a');
	ft_printf("ft_printf value is : %6c\n", 'a');

	printf("   printf value is : %-2c\n", 'a');
	ft_printf("ft_printf value is : %-2c\n", 'a');

	printf("   printf value is : %s\n", "hello world");
	ft_printf("ft_printf value is : %s\n", "hello world");

	printf("   printf value is : %*s\n", 10, "hello world");
	ft_printf("ft_printf value is : %*s\n", 10, "hello world");

	printf("   printf value is : %15s\n", "hello");
	ft_printf("ft_printf value is : %15s\n", "hello");

	printf("   printf value is : %-15s\n", "hello");
	ft_printf("ft_printf value is : %-15s\n", "hello");

	a = printf("printf value is : %-15s\n", "hello");
	b = ft_printf("ft_printf value is : %-15s\n", "hello");

	printf("   printf value is : %.4s\n", "hello");
	ft_printf("ft_printf value is : %.4s\n", "hello");


	printf("printf return : %d, ft_printf return %d\n", a, b);

}
