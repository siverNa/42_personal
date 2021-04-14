#include <stdio.h>
#include <stdlib.h>
#include "../minilibx-linux/mlx.h"

#define WIN_WIDTH 		800
#define WIN_HEIGHT 		600

#define IMG_WIDTH		400
#define	IMG_HEIGHE		300

#define X_EVENT_KEY_PRESS		2
#define X_EVENT_KEY_RELEASE		3
#define X_EVENT_KEY_EXIT		17

#define KEY_ESC					65307

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	//아래 3개 값은 이해안해도 사용하는데 지장없다함
	//선언한 뒤 함수의 인자로만 잘 넣어주면 알아서 정보를 받아온다함.
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

/* 안되어서 주석처리
typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
}				t_mlx;
*/

int		key_press(int keycode)
{
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

int		main()
{
	void		*mlx;
	void		*win;
	int			count_w;
	int			count_h;
	t_img		img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "make_img");
	img.img_ptr = mlx_new_image(mlx, IMG_WIDTH, IMG_HEIGHE);
	img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l, &img.endian);
	//여기서 (int *)안해주고 img.data가 void * 이면 밑에 배열값들을 참조할 때마다 4를 곱해야한다함.
	//그렇기때문에 (int *)로 캐스팅해주는 편이 좋다고 함
	
	count_h = -1;
	while (++count_h < IMG_HEIGHE)
	{
		count_w = -1;
		while (++count_w < IMG_WIDTH)
		{
			if (count_w % 2) //나머지가 1이면
				img.data[count_h * IMG_WIDTH + count_w] = 0xFFFFFF;
			else //나머지가 0이면
				img.data[count_h * IMG_WIDTH + count_w] = 0xFF0000;
		}
	}
	mlx_put_image_to_window(mlx, win, img.img_ptr, 0, 0);
	mlx_hook(win, X_EVENT_KEY_PRESS, 1L >> 0, &key_press, 0);
	mlx_loop(mlx);
	return (0);
}
