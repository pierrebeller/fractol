#include "fractol.h"

int		ft_mandelbrot(t_window *env, t_point pt)
{
	int color;
	int i;
	t_mandelbrot complex;
	double tmp;
	int max;

	max = env->i_max;
	complex = new_mandel_complex(x, y, env);
	i = 0;
	while (1)
	{
		tmp = complex.zr;
		complex.zr = complex.zr * complex.zr - complex.zi * complex.zi + complex.cr;
		complex.zi = 2 * complex.zi * tmp + complex.ci;
		i++;
		if (((complex.zr * complex.zr + complex.zi * complex.zi) >= 4) || i >= max)
			break;
	}
	color = get_rgb_color(env->x_mouse % 50 * i, env->y_mouse % 150 * i,\
		(env->x_mouse + env->y_mouse) % 250 * i);
	return (color);
}