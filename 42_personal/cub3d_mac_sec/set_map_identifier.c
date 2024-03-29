/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_identifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:33:19 by sna               #+#    #+#             */
/*   Updated: 2021/05/24 16:17:47 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		set_screen_size(t_game *game)
{
	int		max_x;
	int		max_y;

	game->screen_size.x = SCREEN_X;
	game->screen_size.y = SCREEN_Y;
	if (!check_resol(game->screen_size.x, game->screen_size.y))
		return (0);
	mlx_get_screen_size(game->mlx, &max_x, &max_y);
	if (game->screen_size.x > max_x)
		game->screen_size.x = max_x;
	if (game->screen_size.y > max_y)
		game->screen_size.y = max_y;
	return (1);
}

int		check_comma(char *line)
{
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ',')
			cnt++;
		i++;
	}
	if (cnt != 2)
		return (0);
	return (1);
}

int		set_fc_color(t_game *game, char *line)
{
	char	**rgb;
	int		color;
	int		i;

	if (!check_comma(line))
		return (0);
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
