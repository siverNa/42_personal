/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 21:49:11 by sna               #+#    #+#             */
/*   Updated: 2022/01/17 21:57:54 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_shell(void)
{
	write(1, "exit\n", 5);
	free_env();
	if (g_home)
		free(g_home);
	if (g_pwd)
		free(g_pwd);
	if (g_oldpwd)
		free(g_oldpwd);
	exit(0);
}
