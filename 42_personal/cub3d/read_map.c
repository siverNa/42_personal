/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 17:29:01 by sna               #+#    #+#             */
/*   Updated: 2021/04/19 18:41:56 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"
#include <stdio.h>

int		read_file(t_game *game, int fd, int *is_finish)
{
	char	*line;
	int		cnt;

	while (get_next_line(fd, &line) > 0)
	{
		cnt = -1;
		*is_finish = 0;
		while (++cnt < 8)
			*is_finish += game->check[cnt];
		if (*is_finish == 8)
		{
			freenull((void **)&line);
			/*
			if (read_map(game, fd, line) == 0)
				return (print_error(0, "wrong map"));
			*/
			break ;
		}
		/*
		if (parsing(game, line) == 0)
		{
			freenull((void **)&line);
			return (print_error(0, "wrong identifier"));
		}
		*/
		printf("%s\n", line);
		freenull((void **)&line);
	}
	return (1);
}

int		open_file(char *file_path, t_game *game)
{
	int		fd;
	int		cnt;
	int		is_finish;

	cnt = 0;
	while (cnt < 8)
		game->check[cnt++] = 0;
	if ((fd = open(file_path, O_RDONLY)) == -1)
		return (print_error(0, "wrong file path"));
	if (read_file(game, fd, &is_finish) == 0)
		return (0);
	close(fd);
	if (is_finish != 8)
		return (0);
	return (1);
}
