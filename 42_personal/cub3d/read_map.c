/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 17:29:01 by sna               #+#    #+#             */
/*   Updated: 2021/04/26 16:22:23 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"
#include <stdio.h>

int		set_player(t_player *player, int y, int x, char dir)
{
	double	radian;
	
	if (dir != 'N' && dir != 'W' && dir != 'S' && dir != 'E')
		return (0);
	/*
	player->pos.x = x + 0.5f;
	player->pos.y = y + 0.5f;
	radian = 3.14159265 / 180;
	
	if (dir == 'W')
		move_camera(player, 90 * radian);
	else if (dir = 'S')
		move_camera(player, 180 * radian);
	else if (dir == 'E')
		move_camera(player, 270 * radian);
	*/

	if (dir == 'W')
		printf("input 'W'\n");
	else if (dir = 'S')
		printf("input 'S'\n");
	else if (dir == 'E')
		printf("input 'E'\n");
	return (1);
}

int		set_map(t_game *game, t_list *map_list)
{
	int		x;
	int		y;
	int		check_pos;
	char	*line;

	check_pos = 0;
	y = 1;
	while (map_list)
	{
		line = (char *)map_list->content;
		x = -1;
		while (line[++x])
		{
			if (set_player(&game->player, y, x + 1, line[x]) >= 1)
			{
				game->map[y][x + 1] = '0';
				check_pos++;
			}
			else
				game->map[y][x + 1] = line[x];
		}
		y++;
		map_list = map_list->next;
	}
	return (check_pos == 1);
}

int		read_map(t_game *game, int fd, char *line)
{
	t_list	*map_list;

	game->map_size.x = 0;
	get_next_line(fd, &line);
	map_list = ft_lstnew(ft_strdup(line));
	freenull((void **)&line);
	while (get_next_line(fd, &line) > 0)
	{
		if (game->map_size.x < ft_strlen(line))
			game->map_size.x = ft_strlen(line);
		ft_lstadd_back(&map_list, ft_lstnew(ft_strdup(line)));
		freenull((void **)&line);
		printf("map reading\n");
	}
	freenull((void **)&line);
	close(fd);
	game->map_size.y = ft_lstsize(map_list);
	padding_map(game);
	if (set_map(game, map_list) == 0)
		return (0);
	ft_lstclear(&map_list, free);
	if (check_map(game) == 0)
	{
		printf("map error\n");
		return (0);
	}
	else
		printf("good\n");
	return (set_sprite(game));
}

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
			if (read_map(game, fd, line) == 0)
				return (print_error(0, "wrong map"));
			break ;
		}
		else
			write(1, "not is_finish 8\n", 16);
		if (parsing(game, line) == 0)
		{
			freenull((void **)&line);
			return (print_error(0, "wrong identifier"));
		}
		//printf("%s\n", line);
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
	{
		printf("cant insert read_file()\n");
		return (0);
	}
	else
		write(1, "success read_file\n", 18);
	close(fd);
	if (is_finish != 8)
	{
		printf("is finish not 8\n");
		return (0);
	}
	return (1);
}
