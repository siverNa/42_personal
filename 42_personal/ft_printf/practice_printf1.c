#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
/*
** 가변 인자 연습
*/ 
void printNumbers(int args, ...)
{
	va_list ap;

	va_start(ap, args);

	for (int i = 0; i < args; i++)
	{
		int num = va_arg(ap, int);
		
		printf("%d ", num);
	}
	printf("\n");
	va_end(ap);
}

int main(void)
{
	printNumbers(1, 10);
	printNumbers(2, 10, 20);
	printNumbers(3, 10, 20, 30);
	printNumbers(4, 10, 20, 30, 40);

	return (0);
}
