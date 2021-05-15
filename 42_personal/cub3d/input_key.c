/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:47:09 by sna               #+#    #+#             */
/*   Updated: 2021/05/13 17:28:46 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void        move_camera(t_player *player, double speed)
{
    double  old_dir_x;
    double  old_plane_x;

    old_dir_x = player->dir.x;
    old_plane_x = player->plane.x;
    player->dir.x = player->dir.x * cos(speed) - player->dir.y * sin(speed);
    player->dir.y = old_dir_x * sin(speed) + player->dir.y * cos(speed);
    player->plane.x = player->plane.x * cos(speed) -
        player->plane.y * sin(speed);
    player->plane.y = old_plane_x * sin(speed) +
        player->plane.y * cos(speed);

}

int			deal_key(int key_code, t_game *game)
{
	if (key_code == KEY_LEFT)
        move_camera(&game->player, game->player.speed);
    if (key_code == KEY_RIGHT)
        move_camera(&game->player, -game->player.speed);
    if (key_code == KEY_ESC)
	{
		free_all(game);
		exit(0);
	}
	return (0);
}

int			close_window(t_game *game)
{
	free_all(game);
	exit(0);
	return (0);
}