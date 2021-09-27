/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:32:52 by sna               #+#    #+#             */
/*   Updated: 2021/09/27 22:03:40 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_cmd *cmd, char **av, char **env)
{
	cmd->file_1 = open(av[1], O_RDONLY);
	if (cmd->file_1 == -1)
	{
		ft_putstr_fd("file1 has problen\n", 2);
		exit(1);
	}
	dup2(cmd->file_1, STDIN_FILENO);
	dup2(cmd->pipefd[1], STDOUT_FILENO);
	close(cmd->pipefd[0]);
	close(cmd->pipefd[1]);
	cmd->cmd_arr = cmd_init(av[2]);
}

void	parent_process(t_cmd *cmd, char **av, char **env, pid_t *pid)
{
	waitpid(*pid, &cmd->status, WNOHANG);
	cmd->file_2 = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (cmd->file_2 == -1)
	{
		ft_putstr_fd("file2 has problem\n", 2);
		exit(1);
	}
	dup2(cmd->pipefd[0], STDIN_FILENO);
	dup2(cmd->file_2, STDOUT_FILENO);
	close(cmd->pipefd[0]);
	close(cmd->pipefd[1]);
	cmd->cmd_arr = cmd_init(av[3]);
}

void	process(t_cmd *cmd, char **av, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		ft_pustr_fd("fork error\n", 2);
		exit(1);
	}
	else if (pid > 0)
		parent_process(cmd, av, env, &pid);
	else if (pid == 0)
		child_process(cmd, av, env);
}