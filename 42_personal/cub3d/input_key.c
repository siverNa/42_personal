/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:47:09 by sna               #+#    #+#             */
/*   Updated: 2021/05/24 11:31:51 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		move_camera(t_player *player, double speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir.x;
	old_plane_x = player->plane.x;
	player->dir.x = player->dir.x * cos(speed) - player->dir.y * sin(speed);
	player->dir.y = old_dir_x * sin(speed) + player->dir.y * cos(speed);
	player->plane.x = player->plane.x * cos(speed) -
					player->plane.y * sin(speed);
	player->plane.y = old_plane_x * sin(speed) +
					player->plane.y * cos(speed);
}

void		move_player_f_b(t_game *game, t_player *player, double speed)
{
	if (game->map[(int)(player->pos.x + player->dir.x * speed)]
			[(int)(player->pos.y)] != '1')
		player->pos.x += player->dir.x * speed;
	if (game->map[(int)(player->pos.x)]
			[(int)(player->pos.y + player->dir.y * speed)] != '1')
		player->pos.y += player->dir.y * speed;
}

void		move_player_r_l(t_game *game, t_player *player, double speed)
{
	if (game->map[(int)(player->pos.x + player->dir.y * speed)]
			[(int)(player->pos.y)] != '1')
		player->pos.x += player->dir.y * speed;
	if (game->map[(int)(player->pos.x)]
			[(int)(player->pos.y + player->dir.x * speed)] != '1')
		player->pos.y += player->dir.x * -speed;
}

int			deal_key(int key_code, t_game *game)
{
	if (key_code == KEY_LEFT)
		move_camera(&game->player, game->player.speed);
	if (key_code == KEY_RIGHT)
		move_camera(&game->player, -game->player.speed);
	if (key_code == KEY_W)
		move_player_f_b(game, &game->player, game->player.speed);
	if (key_code == KEY_S)
		move_player_f_b(game, &game->player, -game->player.speed);
	if (key_code == KEY_A)
		move_player_r_l(game, &game->player, -game->player.speed);
	if (key_code == KEY_D)
		move_player_r_l(game, &game->player, game->player.speed);
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
