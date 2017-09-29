#include "fractol.h"
#include "libft.h"
#include <stdlib.h>

t_mandelbrot *new_mandel_complex(t_env *env)
{
	t_fractol *fractal;

	fractal = (t_mandelbrot *)malloc(sizeof(t_mandelbrot));
	fractal->p1 = ft_dpoint_init(-2.1, -1.2);
	fractal->p2 = ft_dpoint_init(0.6, 1.2);
	fractal->zoom = ft_dpoint_init(WIN_H / (fractal->p2->x - fractal->p1->x)
		* env->mouse_zoom, WIN_W / (fractal->p2->y - fractal->p1->y) *
															env->mouse_zoom);
	(void)env;
	return (fractal);
}
