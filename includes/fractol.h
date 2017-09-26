#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include <mlx.h>

# define WIN_W 800
# define WIN_H 800
# define MAX_ZOOM 3000000
# define INITIAL_LOOP 60

typedef struct 		s_window
{
	void			*mlx;
	void			*win;
	char 			*data;
	void			*img;
	int				size;
	int				endian;
	int				color;
	int 			zoom;
	int				i_max;
	double			x_move;
	double			y_move;
	int				x_mouse;
	int				y_mouse;
	double			mouse_zoom;
	double			offset_x;
	double			offset_y;
}					t_window;

typedef struct 		s_mandelbrot
{
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		zr;
	double		zi;
	double		cr;
	double		ci;
	double		tmp;
}					t_mandelbrot;

#endif