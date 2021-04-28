/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:42:09 by sna               #+#    #+#             */
/*   Updated: 2021/04/28 17:18:22 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			game_init(t_game *game)
{
	int			i;
	int			j;

	game->mlx = mlx_init();
	game->texture = (int **)malloc(sizeof(int *) * 5);
	if (!(game->texture))
		return (0);
	i = -1;
	while (++i < 5)
	{
		game->texture[i] = (int *)malloc(sizeof(int) * (TEXHEIGHT * TEXWIDTH));
		if (!(game->texture[i]))
			return (0);
		j = -1;
		while (++j < TEXHEIGHT * TEXWIDTH)
			game->texture[i][j] = 0;
	}
	return (1);
}

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

int			window_init(t_game *game, int width, int height)
{
	int			w;
	int			h;

	game->win = mlx_new_window(game->mlx, width, height, "cub3d");
	game->img.img = mlx_new_image(game->mlx, width, height);
	game->img.data = (int *)mlx_get_data_addr(game->img.img,
			&game->img.bpp, &game->img.size_l, &game->img.endian);
}

int 		main(int argc, char **argv)
{
	t_game		game;

	if (game_init(&game) == 0)
		return (0);
	if (argc >= 2 && argc <= 3)
	{
		if (check_file_extension(argv[1]) == 0)
			return (print_error(0, "wrong file extension"));
		if (open_file(argv[1], &game) == 0)
			return (print_error(0, "someting wrong"));
		if (window_init(&game, game.screen_size.x, game.screen_size.y) == 0)
			return (print_error(free_map((void **)game.texture, 5),
						"malloc error"));
	}
	else
		print_error(free_map((void **)game.texture, 5), "wrong argument num");

	mlx_hook(game.win, X_EVENT_KEY_PRESS, 1L >> 0, &deal_key, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 1L >> 0, &close_window, &game);

	mlx_loop(game.mlx);
	return (0);
}
