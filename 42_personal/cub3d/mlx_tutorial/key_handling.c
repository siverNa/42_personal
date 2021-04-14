#include <stdio.h>
#include <stdlib.h>
#include "../minilibx-linux/mlx.h"

#define X_EVENT_KEY_PRESS		2
#define X_EVENT_KEY_RELEASE		3
#define X_EVENT_KEY_EXIT		17

/*
** linux 키 코드, mac은 완전히다름
*/
#define KEY_ESC					65307
#define KEY_Q					113
#define KEY_W					119
#define KEY_E					101
#define KEY_R					114
#define KEY_A					97
#define KEY_S					115
#define KEY_D					100

typedef struct s_param
{
	int			x;
	int			y;
	char		str[3];
}				t_param;

void			param_init(t_param *param)
{
	param->x = 3;
	param->y = 4;
	param->str[0] = 'a';
	param->str[1] = 'b';
	param->str[2] = '\0';
}

int				key_press(int keycode, t_param *param)
{
	static int	a;

	a = 0;
	if (keycode == KEY_W)
		param->x++;
	else if (keycode == KEY_S)
		param->x--;
	else if (keycode == KEY_ESC)
		exit(0);
	printf("x : %d\n", param->x);
	return (0);
}

int				main(void)
{
	void		*mlx;
	void		*win;
	t_param		param;

	param_init(&param);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "key_handling");
	printf("----------------------------\n");
	printf("'W key' : Add 1 to x.\n");
	printf("'S key' : Subtract 1 from x.\n");
	printf("'ESC key' : Exit this program.\n");
	printf("'Other keys' : print current x.\n");
	printf("----------------------------\n");
	printf("Current x = 3\n");
	mlx_hook(win, X_EVENT_KEY_PRESS, 1L >> 0, &key_press, &param);
	mlx_loop(mlx);
}
