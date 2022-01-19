/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:06:29 by sna               #+#    #+#             */
/*   Updated: 2022/01/19 23:48:02 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_prompt(void)
{
	char	*cur_path;
	char	buff[4096 + 1];
	int		ret;

	cur_path = getcwd(buff, 4096);
	if (ft_strncmp(cur_path, g_home, ft_strlen(g_home) + 1) == 0)
		ft_putstr_fd("~", 1);
	else
		ft_putstr_fd(cur_path, 1);
	ft_putstr_fd("$ ", 1);
}

void	shell_init(int ac, char **av, char **env)
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
	/*
	** set_exit_code("0");
	*/
	check_sig();
}

int	main(int ac, char **av, char **env)
{

}
