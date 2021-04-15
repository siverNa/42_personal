/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:53:04 by sna               #+#    #+#             */
/*   Updated: 2021/04/15 18:54:28 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "libft/libft.h"
/*
** if use mac, modify "./mlx/mlx.h", maybe
*/
# include "./minilibx-linux/mlx.h"

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_EXIT		17
/*
** This keycode for WSL2, modify for mac keycode
*/
# define KEY_ESC				65307
# define KEY_W					119
# define KEY_A					97
# define KEY_S					115
# define KEY_D					100
# define KEY_UP					65362
# define KEY_DOWN				65364
# define KEY_LEFT				65361
# define KEY_RIGHT				65363
# define TEXWIDTH				64
# define TEXHEIGHT				64

typedef struct	s_vector
{
	double		x;
	double		y;
}				t_vector;

typedef struct	s_img
{
	void		*img;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
	int			img_width;
	int			img_height;
}				t_img;

typedef	struct	s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	char		**map;
}				t_game;

int				deal_key(int key_code, t_game *game);
int				close_window(t_game *game);
int				print_error(int e_code, char *msg);
int				check_file_extension(char *file);	
void			window_init(t_game *game);

#endif
