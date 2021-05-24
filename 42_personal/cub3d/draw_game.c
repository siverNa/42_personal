/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:55:52 by sna               #+#    #+#             */
/*   Updated: 2021/05/24 11:43:17 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_screen(t_game *game)
{
	int			w;
	int			h;

	h = 0;
	while (h < game->screen_size.y)
	{
		w = 0;
		while (w < game->screen_size.x)
		{
			game->img.data[h * (int)game->screen_size.x + w] = game->buf[h][w];
			w++;
		}
		h++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}

void	draw_wall(t_game *game, t_ray ray, int x, t_vector tex)
{
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		step;
	double		tex_pos;

	line_height = (int)(game->screen_size.y / ray.perp_wall_dist);
	draw_start = -line_height / 2 + game->screen_size.y / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + game->screen_size.y / 2;
	if (draw_end >= game->screen_size.y)
		draw_end = game->screen_size.y - 1;
	step = 1.0 * TEXHEIGHT / line_height;
	tex_pos = (draw_start - game->screen_size.y / 2 +
	line_height / 2) * step;
	while (draw_start < draw_end)
	{
		tex.y = (int)tex_pos & (TEXHEIGHT - 1);
		tex_pos += step;
		game->buf[draw_start][x] =\
			game->texture[ray.side][TEXHEIGHT * (int)tex.y + (int)tex.x];
		draw_start++;
	}
}

void	draw_floor_ceil(t_game *game, int floor, int ceil)
{
	int			x;
	int			y;
	int			color;

	color = ceil;
	y = -1;
	while (++y < game->screen_size.y)
	{
		x = -1;
		while (++x < game->screen_size.x)
		{
			if (y > game->screen_size.y / 2)
				color = floor;
			game->buf[y][x] = color;
		}
	}
}
