/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:06:29 by sna               #+#    #+#             */
/*   Updated: 2022/01/17 23:08:50 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void shell_init(int ac, char **av, char **env)
{
	(void)av;
	(void)env;
	init_env(env);
	g_home = NULL;
	g_pwd = NULL;
	g_oldpwd = NULL;
	g_home = ft_strdup(g_env[search_env("HOME")].value);
	g_pwd = ft_strdup(g_env[search_env("PWD")].value);
	g_oldpwd = ft_strdup(g_env[search_env("OLDPWD")].value);
	if (!(g_home) || !(g_pwd) || !(g_oldpwd))
		exit_shell();
}

int main(int ac, char **av, char **env)
{

}