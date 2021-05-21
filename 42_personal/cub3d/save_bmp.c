/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:40:31 by sna               #+#    #+#             */
/*   Updated: 2021/05/21 18:24:21 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void size_to_char(unsigned char *ary, int value)
{
    ary[0] = (unsigned char)(value);
    ary[1] = (unsigned char)(value >> 8);
    ary[2] = (unsigned char)(value >> 16);
    ary[3] = (unsigned char)(value >> 24);
}

static void set_bmp_header(t_game *game, int bmp, int filesize)
{
    unsigned char   header[54];

    ft_memset(header, 0, 54);
    header[0] = (unsigned char)('B');
    header[1] = (unsigned char)('M');
    size_to_char(header + 2, filesize);
    header[10] = (unsigned char)(54);
    header[14] = (unsigned char)(40);
    size_to_char(header + 18, game->screen_size.x);
    size_to_char(header + 22, game->screen_size.y);
    header[26] = (unsigned char)(1);
    header[28] = (unsigned char)(24);
    write(bmp, header, 54);
}

static int set_bmp_color(t_game *game, int bmp)
{
    unsigned char   zero[3];
    int             x;
    int             y;
    int             pad;

    pad = (4 - ((int)game->screen_size.x * 3) % 4) % 4;
    ft_memset(zero, 0, 3);
    y = game->screen_size.y - 1;
    while (y >= 0)
    {
        x = 0;
        while (x < game->screen_size.x)
        {
            if (write(bmp, &game->buf[y][x], 3) < 0)
                return (0);
            if (pad > 0 && write(bmp, &zero, pad) < 0)
                return (0);
            x++;
        }
        y--;
    }
    return (1);
}

int         save_bmp(t_game *game, char *input)
{
    int             bmp;
    
    if (input)
    {
        if (!ft_strncmp(input, "--save", 7))
        {
            if ((bmp = open("save_screen.bmp", O_WRONLY | O_CREAT |
            O_APPEND | O_TRUNC, 00755)) < 0)
                return(print_error(0, "fail save bmp"));
            raycasting(game);
            set_bmp_header(game, bmp, 54 +
            (3 * game->screen_size.x * game->screen_size.y));
            set_bmp_color(game, bmp);
            close(bmp);
            return (1);
        }
    }
    if (game->texture)
        free_map((void **)game->texture, 5);
    return (print_error(0, "wrong input option"));
}