#include "pipex_prec.h"

static void	cmd_init(const char *cmd, t_cmd *strt)
{
	char	**chunk;

	chunk = ft_split(cmd, ' ');
	strt->cmd = ft_strjoin("/bin/", chunk[0]);
	strt->argv = (char *const *)chunk;
	strt->envp = NULL;
}

static void	connect_pipe(int pipefd[2], int io)
{
	dup2(pipefd[io], io);
	close(pipefd[0]);
	close(pipefd[1]);
}

int			redirect_in(const char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror(file);
		return (-1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

int			redirect_out(const char *file)
{
	int fd;
	fd = open(file, O_RDWR | O_CREAT, 0644);
	if (fd < 0)
	{
		perror(file);
		return (-1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

int main(int argc, char const **argv)
{
	int		pipefd[2];
	pid_t	pid;
	t_cmd	cmd;

	if (argc == 5)
	{
		pipe(pipefd);
		pid = fork();
		if (pid > 0)
		{
			redirect_out(FILE_2);
			connect_pipe(pipefd, STDIN_FILENO);
			cmd_init(CMD_2, &cmd);
			if (execve(cmd.cmd, cmd.argv, cmd.envp) == -1)
				perror(cmd.cmd);
		}
		else if (pid == CHILD)
		{
			redirect_in(FILE_1);
			connect_pipe(pipefd, STDOUT_FILENO);
			cmd_init(CMD_1, &cmd);
			if (execve(cmd.cmd, cmd.argv, cmd.envp) == -1)
				perror(cmd.cmd);
		}
	}
	return (0);
}