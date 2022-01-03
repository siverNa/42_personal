#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_zone
{
	int		width;
	int		height;
	char	background;
}				t_zone;

typedef struct	s_shape
{
	char	t;
	float	x;
	float	y;
	float	f_w;
	float	f_h;
	char	color;
}				t_shape;

int ft_strlen(char const *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);   
}

int	print_error(char const *str)
{
	if (str)
		write(1, str, ft_strlen(str));
	return (1);
}

int clear_draw(FILE *file, char *drawing, char const *str)
{
	if (file)
		fclose(file);
	if (drawing)
		free(drawing);
	if (str)
		print_error(str);
	return (1);
}

char *get_zone(FILE *file, t_zone *zone)
{
	int		i;
	char	*temp;

	if (fscanf(file, "%d %d %c\n", &zone->width, &zone->height, &zone->background) != 3)
		return (NULL);
	if (zone->width <= 0 || zone->width > 300 || zone->height <= 0 || zone->height > 300)
		return (NULL);
	if (!(temp = (char *)malloc(sizeof(*temp) * (zone->width * zone->height))))
		return (NULL);
	i = 0;
	while (i < zone->width * zone->height)
		temp[i++] = zone->background;
	return (temp);
}

int	in_rectengle(float x, float y, t_shape *shape)
{
	if (x < shape->x || shape->x + shape->f_w < x
		|| y < shape->y || shape->y + shape->f_h < y)
		return (0);
	if (x - shape->x < 1.00000000 || (shape->x + shape->f_w) - x < 1.00000000
		|| y - shape->y < 1.00000000 || (shape->y + shape->f_h) - y < 1.00000000)
		return (2);
	return (1);
}

void draw_shape(t_zone *zone, char **drawing, t_shape *shape)
{
	int		x;
	int		y;
	int		is_it;

	y = 0;
	while (y < zone->height)
	{
		x = 0;
		while (x < zone->width)
		{
			is_it = in_rectengle((float)x, (float)y, shape);
			if ((shape->t == 'r' && is_it == 2)
				|| (shape->t == 'R' && is_it))
				(*drawing)[(y * zone->width) + x] = shape->color;
			x++;
		}
		y++;
	}
}

int draw_shapes(FILE *file, t_zone *zone, char **drawing)
{
	t_shape	temp;
	int		ret;

	while ((ret = fscanf(file, "%c %f %f %f %f %c\n", &temp.t, &temp.x, &temp.y, &temp.f_w, &temp.f_h, &temp.color)) == 6)
	{
		if (temp.f_w <= 0.00000000 || temp.f_h <= 0.00000000
			|| (temp.t != 'r' && temp.t != 'R'))
			return (0);
		draw_shape(zone, drawing, &temp);
	}
	if (ret != -1)
		return (0);
	return(1);
}


void draw_drawing(t_zone *zone, char *drawing)
{
	int		i;

	i = 0;
	while (i < zone->height)
	{
		write(1, drawing + (i * zone->width), zone->width);
		write(1, "\n", 1);
		i++;
	}
}

int main(int ac, char **av)
{
	t_zone	zone;
	FILE	*file;
	char	*drawing;

	zone.width = 0;
	zone.height = 0;
	zone.background = 0;
	drawing = NULL;

	if (ac != 2)
		return (print_error("Error: argument\n"));
	if (!(file = fopen(av[1], "r")))
		return (print_error("Error: Operation file corrupted\n"));
	if (!(drawing = get_zone(file, &zone)))
		return (clear_draw(file, NULL, "Error: Operation file corrupted\n"));
	if (!(draw_shapes(file, &zone, &drawing)))
		return (clear_draw(file, drawing, "Error: Operation file corrupted\n"));
	draw_drawing(&zone, drawing);
	clear_draw(file, drawing, NULL);
	return (0);
}