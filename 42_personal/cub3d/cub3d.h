/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:53:04 by sna               #+#    #+#             */
/*   Updated: 2021/05/13 17:20:32 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
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

typedef struct	s_sprite
{
	double		x;
	double		y;
	double		distance;
}				t_sprite;

typedef struct	s_player
{
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
	double		speed;
}				t_player;

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
	int			**texture;
	int			**buf;
	int			check[8];
	t_vector	map_size;
	int			sprite_num;
	t_player	player;
	t_vector	screen_size;
	t_vector	fc_color;
	t_sprite	*sprite;
	double		*z_buffer;
}				t_game;

typedef struct	s_ray
{
	t_vector	side_dist;
	t_vector	delta_dist;
	double		perp_wall_dist;
	t_vector	step;
	int			side;
}				t_ray;

typedef struct	s_sprite_ray
{
	t_vector	draw_start;
	t_vector	draw_end;
	t_vector	pos;
	t_vector	tex;
	t_vector	transform;
	t_vector	size;
}				t_sprite_ray;

/*
** cub3d.c
*/
int				game_init(t_game *game);
int				window_init(t_game *game, int width, int height);
void			start_game(t_game *game);
/*
** cub3d_util.c
*/
int				free_all(t_game *game);
int				free_map(void **map, int cnt);
void			freenull(void **var);
int				print_error(int e_code, char *msg);
/*
** read_map.c
*/
int				open_file(char *file_path, t_game *game);
int				read_file(t_game *game, int fd, int *is_finish);
int				read_map(t_game *game, int fd, char *line);
int				set_map(t_game *game, t_list *map_list);
int				set_player(t_player *player, int y, int x, char dir);
/*
** check_map.c
*/
int				padding_map(t_game *game);
int				check_hole(t_game *game, int y, int x);
int				check_map(t_game *game);
int				check_file_extension(char *file);
/*
** check_map_identifier.c
*/
int				check_id(char **arr, int max);
int				check_idnum(t_game *game, int id, int op);
int				parsing(t_game *game, char *line);
/*
** set_map_identifier.c
*/
int				set_screen_size(t_game *game, char *line);
int				set_sprite(t_game *game);
int				set_fc_color(t_game *game, char *line);
int				set_texture(t_game *game, char *line, int dir);
/*
** raycast.c
*/
int				get_tex_width(t_vector pos, t_vector ray_dir, t_ray ray);
t_ray			init_dda(t_vector pos, t_vector ray_dir, t_vector map);
double			dda(t_game *game, t_vector ray_dir, t_vector *map, t_ray *ray);
int				raycasting(t_game *game);
/*
** draw_game.c
*/
void    		draw_screen(t_game *game);
void			draw_wall(t_game *game, t_ray ray, int x, t_vector tex);
void			draw_floor_ceil(t_game *game, int floor, int ceil);
/*
** check_sprite.c
*/
void    		draw_sprite(t_game *game, t_sprite_ray spr_ray,
							int spr_screen_x);
void    		init_sprite_ray(t_game *game, t_sprite_ray *spr_ray,
							int *spr_screen_x, int i);
void    		present_sprite(t_game *game);
void    		sort_sprite(t_game *game);
/*
** input_key.c
*/
void        	move_camera(t_player *player, double speed);
int				deal_key(int key_code, t_game *game);
int				close_window(t_game *game);

#endif
