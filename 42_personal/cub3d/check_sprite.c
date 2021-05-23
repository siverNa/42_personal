/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 11:18:51 by sna               #+#    #+#             */
/*   Updated: 2021/05/23 18:47:56 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    draw_sprite(t_game *game, t_sprite_ray spr_ray, int spr_screen_x)
{
    int             x;
    int             y;
    int             color;
    t_vector        tex;

    x = spr_ray.draw_start.x - 1;
    while (++x < spr_ray.draw_end.x)
    {
        tex.x = (int)((256 * (x - (-spr_ray.size.x / 2 + spr_screen_x)) *
            TEXWIDTH / spr_ray.size.x) / 256);
        if (spr_ray.transform.y > 0 && x > 0 && x < game->screen_size.x &&
            spr_ray.transform.y < game->z_buffer[x])
        {
            y = spr_ray.draw_start.y - 1;
            while (++y < spr_ray.draw_end.y)
            {
                tex.y = ((((y - (int)(0.0f / spr_ray.transform.y)) * 256 -
                game->screen_size.y * 128 + spr_ray.size.y * 128) * TEXHEIGHT)
                / spr_ray.size.y) / 256;
                color = game->texture[4][TEXWIDTH * (int)tex.y + (int)tex.x];
                if ((color & 0x00FFFFFF) != 0)
                    game->buf[y][x] = color;
            }
        }
    }
}

void    init_sprite_ray(t_game *game, t_sprite_ray *spr_ray,
                        int *spr_screen_x, int i)
{
    double          inv_det;
    int             u_div;
    int             v_div;

    u_div = 1;
    v_div = 1;
    spr_ray->pos.x = game->sprite[i].x - game->player.pos.x;
    spr_ray->pos.y = game->sprite[i].y - game->player.pos.y;
    inv_det = 1.0 / (game->player.plane.x * game->player.dir.y -
        game->player.dir.x * game->player.plane.y);
    spr_ray->transform.x = inv_det * (game->player.dir.y * spr_ray->pos.x -
        game->player.dir.x * spr_ray->pos.y);
    spr_ray->transform.y = inv_det * (-game->player.plane.y * spr_ray->pos.x +
        game->player.plane.x * spr_ray->pos.y);
    spr_ray->size.y = (int)fabs((game->screen_size.y / spr_ray->transform.y) /
        v_div);
    spr_ray->size.x = (int)fabs((game->screen_size.y / spr_ray->transform.y) /
        u_div);
    *spr_screen_x = (int)((game->screen_size.x / 2) * (1 +
        spr_ray->transform.x / spr_ray->transform.y));
}

void    present_sprite(t_game *game)
{
    int             i;
    int             spr_screen_x;
    t_sprite_ray    spr_ray;

    i = -1;
    while (++i < game->sprite_num)
    {
        init_sprite_ray(game, &spr_ray, &spr_screen_x, i);
        spr_ray.draw_start.y = (int)-spr_ray.size.y / 2 +
            game->screen_size.y / 2 + (int)(0.0f / spr_ray.transform.y);
        if (spr_ray.draw_start.y < 0)
            spr_ray.draw_start.y = 0;
        spr_ray.draw_end.y = (int)spr_ray.size.y / 2 +
            game->screen_size.y / 2 + (int)(0.0f / spr_ray.transform.y);
        if (spr_ray.draw_end.y >= game->screen_size.y)
            spr_ray.draw_end.y = (int)game->screen_size.y - 1;
        spr_ray.draw_start.x = (int)-spr_ray.size.x / 2 + spr_screen_x;
        if (spr_ray.draw_start.x < 0)
            spr_ray.draw_start.x = 0;
        spr_ray.draw_end.x = (int)spr_ray.size.x / 2 + spr_screen_x;
        if (spr_ray.draw_end.x >= game->screen_size.x)
            spr_ray.draw_end.x = (int)game->screen_size.x - 1;
        draw_sprite(game, spr_ray, spr_screen_x);
    }
}

void    sort_sprite(t_game *game)
{
    int             i;
    int             j;
    t_sprite        temp;

    i = -1;
    while (++i < game->sprite_num)
    {
        game->sprite[i].distance = ((game->player.pos.x - game->sprite[i].x) *
            (game->player.pos.x - game->sprite[i].x) + (game->player.pos.y -
            game->sprite[i].y) * (game->player.pos.y - game->sprite[i].y));
    }
    i = -1;
    while (++i < game->sprite_num)
    {
        j = -1;
        while (++j < game->sprite_num - 1)
        {
            if (game->sprite[j].distance < game->sprite[j + 1].distance)
            {
                temp = game->sprite[j];
                game->sprite[j] = game->sprite[j + 1];
                game->sprite[j + 1] = temp;
            }
        }
    }
}