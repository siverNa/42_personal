/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_identifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:33:19 by sna               #+#    #+#             */
/*   Updated: 2021/04/28 17:47:07 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		set_screen_size(t_game *game, char *line)
{
	char	**resol;

	if (!(resol = ft_split(line + 2, ' ')))
		return (0);
	if (check_id(resol, 2) == 0)
		return (0);
	game->screen_size.x = ft_atoi(resol[0]);
	game->screen_size.y = ft_atoi(resol[1]);
	if (game->screen_size.x > 1920)
		game->screen_size.x = 1920;
	if (game->screen_size.y > 1080)
		game->screen_size.y = 1080;
	free_map((void **)resol, 2);
	return (1);
}

int		set_sprite(t_game *game)
{
	int		x;
	int		y;
	int		cnt;

	game->sprite = (t_sprite *)malloc(sizeof(t_sprite) * game->sprite_num);
	if (!(game->sprite))
		return (0);
	cnt = 0;
	y = -1;
	while (++y < game->map_size.y)
	{
		x = -1;
		while (++x < game->map_size.x)
		{
			if (game->map[y][x] == '2')
			{
				game->sprite[cnt].x = y + 0.5f;
				game->sprite[cnt].y = x + 0.5f;
				cnt++;
			}
		}
	}
	return (1);
}

int		set_fc_color(t_game *game, char *line)
{
	char	**rgb;
	int		color;
	int		i;

	if (!(rgb = ft_split(line + 2, ',')))
		return (0);
	if (check_id(rgb, 3) == 0)
		return (0);
	i = 0;
	color = 0;
	while (rgb[i])
	{
		color = color * 256;
		color = color + ft_atoi(rgb[i++]);
	}
	if (*line == 'F')
		game->fc_color.x = color;
	else
		game->fc_color.y = color;
	free_map((void **)rgb, 3);
	return (1);
}

int		set_texture(t_game *game, char *line, int dir)
{
	int		x;
	int		y;
	t_img	img;

	img.img = mlx_xpm_file_to_image(game->mlx, line,
			&img.img_width, &img.img_height);
	if (!(img.img))
		return (0);
	img.data = (int *)mlx_get_data_addr(img.img, &img.bpp,
			&img.size_l, &img.endian);
	y = -1;
	while (++y < img.img_height)
	{
		x = -1;
		while (++x < img.img_width)
			game->texture[dir][img.img_width *
				y + x] = img.data[img.img_width * y + x];
	}
	mlx_destroy_image(game->mlx, img.img);
	return (1);
}
