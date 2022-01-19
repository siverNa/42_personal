/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:02:14 by sna               #+#    #+#             */
/*   Updated: 2022/01/19 23:47:35 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <signal.h>

typedef struct s_env
{
	char			*key;
	char			*value;
}					t_env;

enum e_flag
{
	CTRL_C,
	CTRL_D,
	CTRL_BS,
	F_SIZE
};

t_env				*g_env;
char				*g_home;
char				*g_pwd;
char				*g_oldpwd;
char				*g_flag[F_SIZE];

/*
** shell_main.c
*/

void	print_prompt(void);
void	shell_init(int ac, char **av, char **env);

/*
** env_func.c
*/

int		search_env(char *key);
t_env	parse_env(char *str);
void	init_env(char **env);
void	free_env(void);

/*
** exit_shell.c
*/

void	exit_shell(void);

/*
** signal_utils.c
*/

void    handle_sig(int whatsig);
void    check_sig(void);

#endif
