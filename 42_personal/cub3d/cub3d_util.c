/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 17:18:56 by sna               #+#    #+#             */
/*   Updated: 2021/05/17 15:44:26 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		free_all(t_game *game)
{
	if (game->img.img)
		mlx_destroy_image(game->mlx, game->img.img);
	free_map((void **)game->texture, 5);
	free_map((void **)game->buf, game->screen_size.y + 1);
	free(game->z_buffer);
	free_map((void **)game->map, game->map_size.y + 1);
	free(game->sprite);
	mlx_destroy_window(game->mlx, game->win);
}

int		free_map(void **map, int cnt)
{
	while (-cnt >= 0)
		free (map[cnt]);
	free(map);
	return (0);
}

void	freenull(void **var)
{
	free(*var);
	*var = 0;
}

int		print_error(int e_code, char *msg)
{
	if (e_code == 0)
	{
	write(1, "Error\n", 6);
	write(1, msg, ft_strlen(msg));
	write(1, "\n", 1);
	}
	return (0);
}

