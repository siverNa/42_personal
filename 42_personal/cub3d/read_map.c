/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 17:29:01 by sna               #+#    #+#             */
/*   Updated: 2021/04/16 17:45:11 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	close(fd);
	if (is_finish != 8)
		return (0);
	return (1);
}
