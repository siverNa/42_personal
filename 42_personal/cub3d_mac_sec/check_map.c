/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:57:03 by sna               #+#    #+#             */
/*   Updated: 2021/05/24 11:34:38 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		g_dirx[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
int		g_diry[8] = {0, 1, 0, -1, -1, 1, 1, -1};

int			padding_map(t_game *game)
{
	int		x;
	int		y;

	game->map_size.x += 2;
	game->map_size.y += 2;
	if (!(game->map = (char **)malloc(sizeof(char *) * (game->map_size.y + 1))))
		return (0);
	game->map[(int)game->map_size.y] = ft_strdup("");
	y = 0;
	while (y < game->map_size.y)
	{
		if (!(game->map[y] = (char *)malloc(sizeof(char) *
						(game->map_size.x + 1))))
			return (0);
		game->map[y][(int)game->map_size.x] = 0;
		x = 0;
		while (x < game->map_size.x)
		{
			game->map[y][x] = ' ';
			x++;
		}
		y++;
	}
	return (0);
}

int			check_hole(t_game *game, int y, int x)
{
	char	loca;
	int		i;

	if (x < 0 || x >= game->map_size.x ||
			y < 0 || y >= game->map_size.y)
		return (1);
	loca = game->map[y][x];
	if (loca == '1' || loca == 'x')
		return (1);
	if (loca != ' ')
		return (0);
	game->map[y][x] = 'x';
	i = -1;
	while (++i < 8)
		if (check_hole(game, y + g_diry[i], x + g_dirx[i]) == 0)
			return (0);
	return (1);
}

int			check_map(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	while (++i < game->map_size.y)
	{
		j = -1;
		while (++j < game->map_size.x)
		{
			if (game->map[i][j] == ' ')
			{
				if (check_hole(game, i, j) == 0)
					return (0);
			}
			else if (game->map[i][j] != '0' && game->map[i][j] != '1' &&
					game->map[i][j] != 'x')
				return (0);
		}
	}
	return (1);
}

int			check_file_extension(char *file)
{
	int		i;
	char	*extension;

	extension = 0;
	i = ft_strlen(file) - 1;
	while (i >= 0)
	{
		if (file[i] == '.')
		{
			extension = file + i;
			break ;
		}
		i--;
	}
	if (!extension)
		return (0);
	return (!ft_strncmp(extension, ".cub", 5));
}
