/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 22:37:38 by sna               #+#    #+#             */
/*   Updated: 2022/01/19 23:49:08 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_sig(int whatsig)
{
	int		status;
	pid_t	pid;

	pid = waitpid(-1, &status, WNOHANG);
	if (whatsig == SIGINT)
	{
		if (pid == -1)
		{
			ft_putstr_fd("\b\b  \b\b\n", 1);
			print_prompt();
			g_flag[CTRL_BS] = 1;
		}
		else
			ft_putstr_fd('\n', 1);
	}
	else if (whatsig == SIGQUIT)
	{
		if (pid == -1)
			ft_putstr_fd("\b\b  \b\b", 1);
		else
			ft_putstr_fd("Quit: 3\n", 1);
	}
}

void	check_sig(void)
{
	signal(SIGINT, handle_sig);
	signal(SIGQUIT, handle_sig);
}
