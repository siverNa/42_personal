/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:32:52 by sna               #+#    #+#             */
/*   Updated: 2021/10/06 20:35:36 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_struct(t_cmd *cmd)
{
	free(cmd->file_path);
	free_2d_arr(cmd->cmd_arr);
	cmd->file_path = NULL;
	cmd->cmd_arr = NULL;
}

void	child_process(t_cmd *cmd, char **av, char **env)
{
	cmd->file_1 = open(av[1], O_RDONLY);
	if (cmd->file_1 == -1)
	{
		ft_putstr_fd("file1 has problem\n", 2);
		exit(1);
	}
	dup2(cmd->file_1, STDIN_FILENO);
	dup2(cmd->pipefd[1], STDOUT_FILENO);
	close(cmd->pipefd[0]);
	close(cmd->pipefd[1]);
	cmd->cmd_arr = cmd_init(av[2]);
	cmd->file_path = build_path(cmd, cmd->cmd_arr[0], env);
	if (execve(cmd->file_path, cmd->cmd_arr, env) == -1)
	{
		ft_putstr_fd("pipex : command not found: ", 2);
		ft_putstr_fd(cmd->cmd_arr[0], 2);
		ft_putstr_fd("\n", 2);
		free_struct(cmd);
		exit(1);
	}
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
	cmd->file_path = build_path(cmd, cmd->cmd_arr[0], env);
	if (execve(cmd->file_path, cmd->cmd_arr, env) == -1)
	{
		ft_putstr_fd("pipex : command not found: ", 2);
		ft_putstr_fd(cmd->cmd_arr[0], 2);
		ft_putstr_fd("\n", 2);
		free_struct(cmd);
		exit(1);
	}
}

void	process(t_cmd *cmd, char **av, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		ft_putstr_fd("fork error\n", 2);
		exit(1);
	}
	else if (pid > 0)
		parent_process(cmd, av, env, &pid);
	else if (pid == 0)
		child_process(cmd, av, env);
}
