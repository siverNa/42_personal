#ifndef MINISHELL_PREC_H
# define MINISHELL_PREC_H
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <signal.h>

typedef struct		s_node
{
	char			**cmd_line;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

#endif