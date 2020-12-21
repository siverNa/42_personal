#include <unistd.h>

//extern char *ft_strcpy(char *desc, char *src);
//extern char *ft_strncpy(char *desc, char *src, unsigned int n);
//extern int ft_str_is_alpha(char *str);
//extern int ft_str_is_numeric(char *str);
//extern int ft_str_is_lowercase(char *str);
//extern int ft_str_is_uppercase(char *str);
//extern int ft_str_is_printable(char *str);
//extern char *ft_strupcase(char *str);
//extern char *ft_strlowcase(char *str);
//extern char *ft_strcapitalize(char *str);
//extern unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);
extern void ft_putstr_non_printable(char *str);

int main()
{
	//ex00
	//char str[] = "";

	//ex01
	//ft_strcpy(str, "hijklm");
	//ft_strncpy(str, "abcd", 5);
	//write(1, &str, 5);
	
	//ex02
	//int i;
	//char c;
	//i = ft_str_is_alpha("aBCD1E");
	//c = '0' + i;
	//write(1, &c, 5);
	
	//ex03
	//int i;
	//char c;
	//i = ft_str_is_numeric("123");
	//c = '0' + i;
	//write(1, &c, 5);
	
	//ex04
	//int i;
	//char c;
	//i = ft_str_is_lowercase("abcD");
	//c = '0' + i;
	//write(1, &c, 5);
	
	//ex05
	//int i;
	//char c;
	//i = ft_str_is_uppercase("ABC");
	//c = '0' + i;
	//write(1, &c, 5);
	
	//ex06
	//int i;
	//char c;
	//i = ft_str_is_printable(" !@#$^aB");
	//c = '0' + i;
	//write(1, &c, 5);

	//ex07
	//char a[] = "abcdeF";
	//char *c = ft_strupcase(a);
	//write(1, c, 6);

	//ex08
	//char a[] = "ABCDEf";
	//char *c = ft_strlowcase(a);
	//write(1, c, 6);

	//ex09
	//char a[] = "agenda oNE + tWo = tHrEE";
	//char *c = ft_strcapitalize(a);
	//write(1, c, 30);

	//ex10
	//int i;
	//char a[] = "";
	//char d[] = "abceasdsa";
	//i = ft_strlcpy(a, d, -1) + '0';
	//write(1, &i, 1);

	//ex11
	char a[] = "occur \n you are \n haha! did you?!! @@123 +/7";
	ft_putstr_non_printable(a);
}
