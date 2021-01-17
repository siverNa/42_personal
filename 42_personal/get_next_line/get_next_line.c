/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:24:05 by sna               #+#    #+#             */
/*   Updated: 2021/01/17 21:13:35 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_line(char **line, char **rem, char *nl_addr)
{
	char		*temp;

	if (nl_addr)
	{
		*line = ft_strdup(*rem);
		temp = ft_strdup(nl_addr + 1);
		free(*rem);
		*rem = temp;
		return (1);
	}
	if (*rem)
	{
		*line = ft_strdup(*rem);
		free(*rem);
		*rem = NULL;
	}
	else
		*rem = ft_strdup("");
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*rem[OPEN_MAX];
	char		buff[BUFFER_SIZE + 1];
	int			rd_len;
	char		*temp;
	char		*nl_addr;

	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE < 1)
		return (-1);
	while ((nl_addr = ft_strchr(rem[fd], '\n')) == 0
			&& (rd_len = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[rd_len] = 0;
		if (rem[fd] == NULL)
			temp = ft_strdup(buff);
		else
			temp = ft_strjoin(rem[fd], buff);
		if (rem[fd] != 0)
			free(rem[fd]);
		rem[fd] = temp;
	}
	if (rd_len < 0)
		return (-1);
	return (get_line(line, &rem[fd], nl_addr));
}
