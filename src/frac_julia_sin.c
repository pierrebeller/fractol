#include <math.h>
#include "fractol.h"

int		ft_julia_sin(t_window *env, t_point *pt)
{
	t_complex	complex;
	int			color;
	double		i;
	double		max;
	double		tmp;

	i = 0;
	max = env->i_max;
	complex = complex_julia_sin_new(env, pt, env->fractal);
	while (1)
	{
		tmp = complex.z.r;
		complex.z.r = complex.z.r * complex.z.r * complex.z.r - 3 *
						(complex.z.r * complex.z.i * complex.z.i) + complex.c.r;
		complex.z.i = 3 * ((tmp * tmp) * complex.z.i) - complex.z.i *
										complex.z.i * complex.z.i + complex.c.i;
		i++;
		if (((complex.z.r * complex.z.r + complex.z.i * complex.z.i) >= 4)
																	|| i >= max)
			break ;
	}
	color = get_rgb_color(env->mouse_pos->x % 50 * i, env->mouse_pos->y %
					150 * i, (env->mouse_pos->x + env->mouse_pos->y) % 250 * i);
	return (color);
}