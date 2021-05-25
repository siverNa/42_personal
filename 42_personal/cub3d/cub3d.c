/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:42:09 by sna               #+#    #+#             */
/*   Updated: 2021/05/25 17:38:12 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		game_init(t_game *game)
{
	int			i;
	int			j;
	t_player	*player;

	player = &game->player;
	player->dir.x = -1;
	player->dir.y = 0;
	player->plane.x = 0;
	player->plane.y = 0.66;
	player->speed = 0.08;
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

int		window_init(t_game *game, int width, int height)
{
	int			w;
	int			h;

	game->win = mlx_new_window(game->mlx, width, height, "cub3d");
	game->img.img = mlx_new_image(game->mlx, width, height);
	game->img.data = (int *)mlx_get_data_addr(game->img.img,
			&game->img.bpp, &game->img.size_l, &game->img.endian);
	if (!(game->buf = (int **)malloc(sizeof(int *) * (height + 1))))
		return (0);
	game->buf[(int)height] = 0;
	h = -1;
	while (++h < height)
	{
		if (!(game->buf[h] = (int *)malloc(sizeof(int) * (width + 1))))
			return (0);
		game->buf[h][(int)width] = 0;
		w = -1;
		while (++w < width)
			game->buf[h][w] = 0;
	}
	if (!(game->z_buffer = (double *)malloc(sizeof(double) * width)))
		return (0);
	return (1);
}

void	start_game(t_game *game)
{
	mlx_loop_hook(game->mlx, &raycasting, game);
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 1L >> 0, &deal_key, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 1L >> 0, &close_window, game);
	mlx_loop(game->mlx);
}

int		main(int argc, char **argv)
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
		{
			return (print_error(free_map((void **)game.texture, 5), "error"));
		}
		if (argc == 3)
		{
			if (save_bmp(&game, argv[2]) == 0)
				return (0);
			exit(0);
		}
		start_game(&game);
	}
	else
		print_error(free_map((void **)game.texture, 5), "wrong argument num");
	return (0);
}
