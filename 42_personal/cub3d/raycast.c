/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:19:18 by sna               #+#    #+#             */
/*   Updated: 2021/05/13 16:26:19 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_tex_width(t_vector pos, t_vector ray_dir, t_ray ray)
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
		return ((map->y - game->player.pos.y + (1 - ray->step.y) / 2)
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
		tex.x = get_tex_width(game->player.pos, ray_dir, ray);
		draw_wall(game, ray, w, tex);
		game->z_buffer[w] = ray.perp_wall_dist;
	}
	sort_sprite(game);
	present_sprite(game);
	draw_screen(game);
	return (0);
}