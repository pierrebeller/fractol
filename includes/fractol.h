#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include <mlx.h>

# define WIN_W 600
# define WIN_H 600
# define MAX_ZOOM 3000000
# define INITIAL_LOOP 100

typedef struct		s_fractol
{
	t_dpoint		*p1;
	t_dpoint		*p2;
	t_dpoint		*zoom;
}					t_fractol;

typedef	struct		s_complex
{
	t_dcomplex		z;
	t_dcomplex		c;
}					t_complex;

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
	double			mouse_zoom;
	double			offset_x;
	double			offset_y;
	t_point			offset;
	int				fractal_type;
	t_point			mouse_position;
	int				is_rendering;
	t_point			mouse_zoom_pos;
	t_point			*mouse_pos;
	t_fractol		*fractal;

}					t_window;

void		error_usage(void);
t_window	*set_env(void);
void		set_new_image(t_window *env);
void		ft_set_hooks(t_window *env);
int			expose_hook(t_window *env);

t_fractol	*julia_new(t_window *env);
t_fractol	*mandelbrot_new(t_window *env);

int			ft_ship(t_window *win, t_point *pt, t_fractol *fractal);
int			ft_mandelbrot(t_window *env, t_point *pt);
int			ft_julia(t_window *env, t_point *pt);

void		env_process_image(t_window *env);
void		env_print_image(t_window *env);

void		env_redraw(t_window *env);

t_complex	new_julia_complex(t_window *env, t_point *pt, t_fractol *fractal);
t_complex 	new_mandel_complex(t_point *pt, t_fractol *fractal);
t_complex 	new_ship_complex(t_point *pt, t_fractol *fractal);

int			get_rgb_color(int r, int g, int b);
int			check_x(int x);
int			check_y(int y);
#endif
