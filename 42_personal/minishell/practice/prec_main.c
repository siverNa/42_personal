#include "minishell_prec.h"

int main(void)
{
	char	*str;
	char	**splited;
	int		i;

	while(1)
	{
		str = readline("practice : ");
		splited = ft_split(str, ' ');
		i = 0;
		while (splited[i])
			printf("splited[%d] : %s\n", i++, splited[i]);
		add_history(str);
		free(str);
	}
	return (0);
}