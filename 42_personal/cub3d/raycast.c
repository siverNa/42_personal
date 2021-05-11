/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:19:18 by sna               #+#    #+#             */
/*   Updated: 2021/05/11 19:15:23 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int		get_texture_width(t_vector pos, t_vector ray_dir, t_ray ray)
{
	int			tex_x;
	double		wall_x;

	if (ray.side <= 1)
		wall_x = pos.y + ray.perp_wall_dist * ray_dir.y;
	else
		wall_x = pos.x + ray.perp_wall_dist * ray_dir.x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)TEXWIDTH);
	if (ray.side == 1 || ray.side == 2)
		tex_x = TEXWIDTH - tex_x - 1;
	return (tex_x);
}

t_ray	init_dda(t_vector pos, t_vector ray_dir, t_vector map)
{
	t_ray 		ray;

	ray.step.x = 1;
	ray.step.y = 1;
	ray.delta_dist.x = fabs(1 / ray_dir.x);
	ray.delta_dist.y = fabs(1 / ray_dir.y);
	ray.side_dist.x = (map.x + 1.0 - pos.x) * ray.delta_dist.x;
	ray.side_dist.y = (map.y + 1.0 - pos.y) * ray.delta_dist.y;
	if (ray_dir.x < 0)
	{
		ray.step.x = -1;
		ray.side_dist.x = (pos.x - map.x) * ray.delta_dist.x;
	}
	if (ray_dir.y < 0)
	{
		ray.step.y = -1;
		ray.side_dist.y = (pos.y - map.y) * ray.delta_dist.y;
	}
	return (ray);
}

double	dda(t_game *game, t_vector ray_dir, t_vector *map, t_ray *ray)
{
	*ray = init_dda(game->player.pos, ray_dir, *map);
	while ((char)game->map[(int)map->x][(int)map->y] != '1')
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			map->x += ray->step.x;
			ray->side = (ray->step.x == -1) ? 0 : 1;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			map->y += ray->step.y;
			ray->side = (ray->step.y == -1) ? 2 : 3;
		}
	if (ray->side <= 1)
		return ((map->x - game->player.pos.x + (1 - ray->step.x) / 2)
		/ ray_dir.x);
	else
		return ((map->y - game->player.pos.y + (1 - ray->step.y) . 2)
		/ ray_dir.y);
}

int		raycasting(t_game *game)
{
	t_vector	ray_dir;
	t_vector	map;
	t_vector	tex;
	t_ray		ray;
	int			w;

	draw_floor_ceil(game, game->fc_color.x, game->fc_color.y);
	w = -1;
	while (++w < game->screen_size.x)
	{
		map.x = (int)game->player.pos.x;
		map.y = (int)game->player.pos.y;
		ray_dir.x = game->player.dir.x +
		game->player.plane.x * (2 * w / game->screen_size.x - 1);
		ray_dir.y = game->player.dir.y +
		game->player.plane.y * (2 * w / game->screen_size.x - 1);
		ray.perp_wall_dist = dda(game, ray_dir, &map, &ray);
		tex.x = get_texture_width(game->player.pos, ray_dir, ray);
		draw_wall(game, ray, w, tex);
		game->z_buffer[w] = ray.perp_wall_dist;
	}
	return (0);
}