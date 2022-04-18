#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define SIDE_OUT		0
#define SIDE_IN			1

#define STDIN			0
#define STDOUT			1
#define STDERR			2

#define TYPE_END		0
#define TYPE_PIPE		1
#define TYPE_BREAK		2

typedef struct	s_list
{
	char			**args;
	int				length;
	int				type;
	int				pipe[2];
	struct	s_list	*prev;
	struct	s_list	*next;
}				t_list;

int		ft_strlen(char const *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		show_error(char const *str)
{
	if (str)
		write(STDERR, str, ft_strlen(str));
	return (EXIT_FAILURE);
}

int		exit_fatal(void)
{
	show_error("error: fatal\n");
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}

void	*exit_fatal_ptr(void)
{
	exit_fatal();
	exit(EXIT_FAILURE);
	return (NULL);
}

char	*ft_strdup(char const *str)
{
	char	*copy;
	int		i;

	if (!(copy = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (exit_fatal_ptr());
	i = 0;
	while (str[i] != '\0')
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int		add_arg(t_list *cmd, char *arg)
{
	char		**temp;
	int			i;

	i = 0;
	temp = NULL;
	if (!(temp = (char **)malloc(sizeof(char *) * (cmd->length + 2))))
		return (exit_fatal());
	while (i < cmd->length)
	{
		temp[i] = cmd->args[i];
		i++;
	}
	if (cmd->length > 0)
		free(cmd->args);
	cmd->args = temp;
	cmd->args[i++] = ft_strdup(arg);
	cmd->args[i] = '\0';
	cmd->length++;
	return (EXIT_SUCCESS);
}

int		list_push(t_list **list, char *arg)
{
	t_list		*new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (exit_fatal());
	new->args = NULL;
	new->length = 0;
	new->type = TYPE_END;
	new->prev = NULL;
	new->next = NULL;
	if (*list)
	{
		(*list)->next = new;
		new->prev = *list;
	}
	*list = new;
	return (add_arg(new, arg));
}

int		parse_arg(t_list **cmds, char *arg)
{
	int			is_break;

	is_break = (strcmp(";", arg) == 0);//;가 있으면 is_break 에 1이 대입됨
	if (is_break && !(*cmds))
		return (EXIT_SUCCESS);
	else if (!is_break && (!*cmds || (*cmds)->type > TYPE_END))
		return (list_push(cmds, arg));
	else if (strcmp("|", arg) == 0)
		(*cmds)->type = TYPE_PIPE;
	else if (is_break)
		(*cmds)->type = TYPE_BREAK;
	else
		return (add_arg(*cmds, arg));
	return (EXIT_SUCCESS);
}

//리스트의 맨 처음으로 돌아가는 함수
int		list_rewind(t_list **list)
{
	while (*list && (*list)->prev)
		*list = (*list)->prev;
	return (EXIT_SUCCESS);
}

int		exec_cmd(t_list *cmd, char **env)
{
	pid_t		pid;
	int			res;
	int			status;
	int			pipe_open;

	res = EXIT_SUCCESS;
	pipe_open = 0;
	if (cmd->type == TYPE_PIPE || (cmd->prev && cmd->prev->type == TYPE_PIPE))
	{
		pipe_open = 1;
		if (pipe(cmd->pipe))
			return (exit_fatal());
	}
	pid = fork();
	if (pid < 0)//fork 실패
		return (exit_fatal());
	else if (pid == 0)//자식 프로세스
	{
		if (cmd->type == TYPE_PIPE
			&& dup2(cmd->pipe[SIDE_IN], STDOUT) < 0)
			return (exit_fatal());
		if (cmd->prev && cmd->prev->type == TYPE_PIPE
			&& dup2(cmd->prev->pipe[SIDE_OUT], STDIN) < 0)
			return (exit_fatal());
		if ((res = execve(cmd->args[0], cmd->args, env)) < 0)
		{
			show_error("error: cannot execute ");
			show_error(cmd->args[0]);
			show_error("\n");
		}
		exit(res);
	}
	else//부모 프로세스
	{
		waitpid(pid, &status, 0);
		if (pipe_open)
		{
			close(cmd->pipe[SIDE_IN]);//먼저 파이프 입력단을 close
			if (!cmd->next || cmd->type == TYPE_BREAK)//다음노드가 없거나 break 만나면 파이프 출력단 close
				close(cmd->pipe[SIDE_OUT]);
		}
		if (cmd->prev && cmd->prev->type == TYPE_PIPE)
			close(cmd->prev->pipe[SIDE_OUT]);
		if (WIFEXITED(status))
			res = WEXITSTATUS(status);
	}
	return (res);
}

int		exec_cmds(t_list **cmds, char **env)
{
	t_list		*crt;
	int			res;
	
	res = EXIT_SUCCESS;
	list_rewind(cmds);
	while (*cmds)
	{
		crt = *cmds;
		if (strcmp("cd", crt->args[0]) == 0)
		{
			res = EXIT_SUCCESS;
			if (crt->length < 2)
				res = show_error("error: cd: bad arguments\n");
			else if (chdir(crt->args[1]))
			{
				res = show_error("error: cd: cannot change to ");
				show_error(crt->args[1]);
				show_error("\n");
			}
		}
		else
			res = exec_cmd(crt, env);
		if (!(*cmds)->next)
			break;
		*cmds = (*cmds)->next;
	}
	return (res);
}

int		list_clear(t_list **cmds)
{
	t_list	*temp;
	int		i;

	list_rewind(cmds);
	while (*cmds)
	{
		temp = (*cmds)->next;
		i = 0;
		while (i < (*cmds)->length)
			free((*cmds)->args[i++]);
		free((*cmds)->args);
		free(*cmds);
		*cmds = temp;
	}
	*cmds = NULL;
	return (EXIT_SUCCESS);
}

int main(int ac, char **av, char **env)
{
	t_list		*cmds;
	int			i;
	int			res;

	res = EXIT_SUCCESS;
	cmds = NULL;
	i = 1;
	while (i < ac)
		parse_arg(&cmds, av[i++]);
	if (cmds)
		res = exec_cmds(&cmds, env);
	list_clear(&cmds);
	return (res);
}