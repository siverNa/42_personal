/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:42:09 by sna               #+#    #+#             */
/*   Updated: 2021/04/15 18:55:33 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			deal_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit(0);
	return (0);
}

int			close_window(t_game *game)
{
	exit(0);
}

int			print_error(int e_code, char *msg)
{
	if (e_code == 0)
	{
		write(1, "Error\n", 6);
		write(1, msg, ft_strlen(msg));
		write(1, "\n", 1);
	}
}

int			check_file_extension(char *file)
{
	int			i;
	char		*extension;

	extension = 0;
	i = ft_strlen(file) - 1;
	while (i >= 0)
	{
		if (file[i] == '.')
		{
			extension = file + i;
			break ;
		}
		i--;
	}
	if (!extension)
		return (0);
	return (!ft_strncmp(extension, ".cub", 5));
}

void		window_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 1280, 1024, "cub3d");
}

int 		main(int argc, char **argv)
{
	t_game		game;

	if (argc >= 2 && argc <= 3)
	{
		if (check_file_extension(argv[1]) == 0)
			return (print_error(0, "wrong file extension"));
	}

	window_init(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 1L >> 0, &deal_key, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 1L >> 0, &close_window, &game);

	mlx_loop(game.mlx);
}
