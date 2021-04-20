/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:57:03 by sna               #+#    #+#             */
/*   Updated: 2021/04/20 18:39:21 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			check_map(t_game *game)
{
	int		i;
	int		j;

	game->sprite_num = 0;
	i = -1;
	while (++i < game->map_size.y)
	{
		j = -1;
		while (++j < game->map_size.x)
		{
			if (game->map[i][j] == ' ')
			{
				//if (check_hole(game, i, j) == 0)
				//	return (0);
			}
			else if (game->map[i][j] == '2')
				game->sprite_num++;
			else if (game->map[i][j] != '0' && game->map[i][j] != '1' &&
					game->map[i][j] != '_')
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

