#include "minishell_prec.h"

void sig_handler(int signum)
{
	if (signum != SIGINT)
		return;
	printf("\b\bctrl + c\n");
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
}

int main(void)
{
	t_node	node;
	char	*str;
	int		i;

	signal(SIGINT, sig_handler);
	while(1)
	{
		str = readline("practice : ");
		node.cmd_line = ft_split(str, ' ');
		i = 0;
		while (node.cmd_line[i])
			printf("splited[%d] : %s\n", i++, node.cmd_line[i]);
		add_history(str);
		free(str);
		i = 0;
		while(node.cmd_line[i])
			free(node.cmd_line[i++]);
		free(node.cmd_line);
		str = NULL;
	}
	return (0);
}
