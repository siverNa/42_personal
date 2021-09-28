/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmd_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 22:04:53 by sna               #+#    #+#             */
/*   Updated: 2021/09/28 23:07:19 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**parsing_str(char *str, char **result, int s_len)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	while(str[i] && j < s_len)
	{
		count = 0;
		if (str[i] != ' ')
		{
			
		}
	}
}

void	count_word(const char *str, int *i, int *count)
{
	if (str[*i] == 34)
	{
		(*i)++;
		while (str[*i] != 34 && str[*i] != '\0')
			(*i)++;
		(*count)++;
	}
	else if (str[*i] == 39)
	{
		(*i)++;
		while (str[*i] != 39 && str[*i] != '\0')
			(*i)++;
		(*count)++;
	}
	else
	{
		while (str[*i] != ' ' && str[*i] != '\0')
			(*i)++;
		(*count)++;
	}
}

int		count_str(const char *str)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			count_word(str, &i, &count);
		if (str[i] == '\0')
			break ;
		else
			i++;
	}
	return (count);
}

char	**cmd_init(const char *str)
{
	int		s_len;
	char	**result;

	if (str == NULL)
		return (NULL);
	s_len = count_str(str);
	result = (char *)malloc(sizeof(char) * s_len + 1);
	if (!result)
		return (NULL);
	parsing_str((char *)str, result, s_len);
}