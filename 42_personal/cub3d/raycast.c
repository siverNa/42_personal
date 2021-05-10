/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:19:18 by sna               #+#    #+#             */
/*   Updated: 2021/05/10 16:31:24 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int		raycasting(t_game *game)
{
	t_vector	ray_dir;
	t_vector	map;
	t_vector	texture;
	t_ray		ray;
	int			w;

	draw_floor_ceil(game, game->fc_color.x, game->fc_color.y);
	return (0);
}
