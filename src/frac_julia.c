#include "fractol.h"

int		ft_julia(t_window *env, t_point pt)
{
	t_complex	complex;
	int			color;
	double		i;
	double		max;
	double		tmp;

	max = env->max_iter;
	i = 0;
	complex = complex_julia_new(env, pt, fractal);
	while (1)
	{
		tmp = complex.z.r;
		complex.z.r = complex.z.r * complex.z.r - complex.z.i * complex.z.i +
																	complex.c.r;
		complex.z.i = 2 * complex.z.i * tmp + complex.c.i;
		i++;
		if (((complex.z.r * complex.z.r + complex.z.i * complex.z.i) >= 4)
																	|| i >= max)
			break ;
	}
	color = get_rgb_color(env->x_mouse % 50 * i, env->y_mouse % 150 * i,\
		(env->x_mouse + env->y_mouse) % 250 * i);
	return (color);
}