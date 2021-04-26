/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:42:09 by sna               #+#    #+#             */
/*   Updated: 2021/04/23 16:03:36 by sna              ###   ########.fr       */
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
		if (open_file(argv[1], &game) == 0)
			return (print_error(0, "someting wrong"));
	}

	window_init(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 1L >> 0, &deal_key, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 1L >> 0, &close_window, &game);

	mlx_loop(game.mlx);
}
