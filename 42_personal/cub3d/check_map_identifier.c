/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_identifier.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:09:52 by sna               #+#    #+#             */
/*   Updated: 2021/04/28 17:19:29 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_id(char **arr, int max)
{
	int		i;
	int		len;

	len = -1;
	while (++len < max)
		if (!arr[len])
			return (free_map((void **)arr, len));
	len = 0;
	while (arr[len])
		len++;
	if (len > max)
		return (free_map((void **)arr, len));
	len = -1;
	while (++len < max)
	{
		i = 0;
		while (arr[len][i] && arr[len][i] == ' ')
			i++;
		while (arr[len][i])
			if (!ft_isdigit(arr[len][i++]))
				return (free_map((void **)arr, max));
	}
	return (1);
}

int		check_idnum(t_game *game, int id, int op)
{
	if (game->check[id] == 1)
		return (0);
	game->check[id] = op;
	return (op);
}

int		parsing(t_game *game, char *line)
{
	if (*line == '\0')
		return (1);
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (check_idnum(game, 0, set_texture(game, line + 3, 0)));
		//return (check_idnum(game, 0, 1));
	if (ft_strncmp(line, "SO ", 3) == 0)
		return (check_idnum(game, 1, set_texture(game, line + 3, 1)));
		//return (check_idnum(game, 1, 1));
	if (ft_strncmp(line, "WE ", 3) == 0)
		return (check_idnum(game, 2, set_texture(game, line + 3, 2)));
		//return (check_idnum(game, 2, 1));
	if (ft_strncmp(line, "EA ", 3) == 0)
		return (check_idnum(game, 3, set_texture(game, line + 3, 3)));
		//return (check_idnum(game, 3, 1));
	if (ft_strncmp(line, "S ", 2) == 0)
		return (check_idnum(game, 4, set_texture(game, line + 2, 4)));
		//return (check_idnum(game, 4, 1));
	if (ft_strncmp(line, "F ", 2) == 0)
		return (check_idnum(game, 5, set_fc_color(game, line)));
	if (ft_strncmp(line, "C ", 2) == 0)
		return (check_idnum(game, 6, set_fc_color(game, line)));
	if (ft_strncmp(line, "R ", 2) == 0)
		return (check_idnum(game, 7, set_screen_size(game, line)));
	return (0);
}
