#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	printf("   printf value is : %c\n", 'a');
	ft_printf("ft_printf value is : %c\n", 'a');
	
	printf("   printf value is : %6c\n", 'a');
	ft_printf("ft_printf value is : %6c\n", 'a');

	printf("   printf value is : %-2c\n", 'a');
	ft_printf("ft_printf value is : %-2c\n", 'a');

}
