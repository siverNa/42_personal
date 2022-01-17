/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:09:17 by sna               #+#    #+#             */
/*   Updated: 2022/01/17 22:27:54 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	search_env(char *key)
{
	int		i;

	i = -1;
	while (g_env[++i].key)
	{
		if (ft_strncmp(g_env[i].key, key, ft_strlen(key) + 1) == 0)
			return (i);
	}
	return (-1);
}

t_env	parse_env(char *str)
{
	char	**splited_str;
	t_env	env;

	splited_str = ft_split(str, "=");
	if (!splited_str)
		exit_shell();
	env.key = splited_str[0];
	env.value = splited_str[1];
	free(splited_str);
	return (env);
}

void	init_env(char **env)
{
	int		i;
	int		size;

	size = 0;
	while (env[size])
		size++;
	g_env = (t_env *)malloc(sizeof(t_env) * (size + 1));
	if (!g_env)
		exit_shell();
	g_env[size].key = NULL;
	g_env[size].value = NULL;
	i = -1;
	while (env[++i])
		g_env[i] = parse_env(env[i]);
}

void	free_env(void)
{
	int		i;

	i = -1;
	while (g_env[++i].key)
	{
		free(g_env[i].key);
		free(g_env[i].value);
	}
	free(g_env);
}
