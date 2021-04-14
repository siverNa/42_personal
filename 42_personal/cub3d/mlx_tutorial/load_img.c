#include <stdio.h>
#include <stdlib.h>
#include "../minilibx-linux/mlx.h"

#define X_EVENT_KEY_PRESS		2
#define X_EVENT_KEY_RELEASE		3
#define X_EVENT_KEY_EXIT		17

#define KEY_ESC					65307

int key_press(int keycode)
{
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

int main()
{
	void	*mlx;
	void	*win;
	void	*img;

	int		img_width;
	int		img_height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "load_img");
	img = mlx_xpm_file_to_image(mlx, "./hello.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 50, 50);
	mlx_hook(win, X_EVENT_KEY_PRESS, 1L >> 0, &key_press, 0);
	mlx_loop(mlx);
	return (0);
}
