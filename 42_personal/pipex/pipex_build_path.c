/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_build_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 21:17:33 by sna               #+#    #+#             */
/*   Updated: 2021/09/30 21:50:29 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    catch_env_to_path(t_cmd *cmd, char **env)
{
    int     i;

    i = 0;
    while (env[i])
    {
        if (!ft_strncmp(env[i], "PATH=", 5))
            cmd->temp_path = env[i] + 5;
        i++;
    }
}

char    *build_path(t_cmd *cmd, char *cmd_line, char **env)
{
    char    **split_path;
    char    *join1;
    char    *join2;
    int     i;

    i = 0;
    if (!ft_strncmp(cmd, '/', 1))
        return (cmd_line);
    catch_env_to_path(cmd, env);
    split_path = ft_split(cmd->temp_path, ':');
    while (split_path[i])
    {
        join1 = ft_strjoin(split_path[i], "/");
        join2 = ft_strjoin(join1, cmd_line);
        free(join1);
        if (access(join2, F_OK | X_OK) == 0)
        {
            
        }
        free(join2);
        i++;
    }
    return (NULL);
}