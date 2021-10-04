/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 21:10:53 by sna               #+#    #+#             */
/*   Updated: 2021/10/04 18:45:08 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_cmd	cmd;

	if (ac != 5)
	{
		ft_putstr_fd("form : ./pipex file1 cmd1 cmd2 file2\n", 2);
		exit(1);
	}
	if (pipe(cmd.pipefd) == -1)
	{
		ft_putstr_fd("pipe fail!\n", 2);
		exit(1);
	}
	process(&cmd, av, env);
	free_struct(&cmd);
	close(cmd.file_1);
	close(cmd.file_2);
	return (0);
}
