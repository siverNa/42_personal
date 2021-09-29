/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 21:07:35 by sna               #+#    #+#             */
/*   Updated: 2021/09/29 22:38:06 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "libft.h"

typedef struct	s_cmd
{
	int		pipefd[2];
	int		status;
	int		file_1;
	int		file_2;
	char	*file_path;
	char	**cmd_arr;
	char	**envp;
}				t_cmd;

typedef struct	s_pars
{
	int		i;
	int		j;
	int		count;
	int		len;
}				t_pars;


/*
** pipex_process.c
*/
void	child_process(t_cmd *cmd, char **av, char **env);
void	parent_process(t_cmd *cmd, char **av, char **env, pid_t *pid);
void	process(t_cmd *cmd, char **av, char **env);
/*
** pipex_cmd_init.c
*/
char	**parsing_str(char *str, char **result, t_pars *pars);
void	count_word(const char *str, int *i, int *count);
int		count_str(const char *str);
char	**cmd_init(const char *str);
/*
** pipex_cmd_init.c
*/

#endif