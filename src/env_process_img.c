#include "fractol.h"

void		draw_pt(t_point *pt, void *context)
{
	t_env	*env;
	int		color;

	env = context;
	pt->x += env->offset.x;
	pt->y += env->offset.y;
	pt->x -= env->offset.x;
	pt->y -= env->offset.y;
	if (env->fract_type == 1)
		ft_mandelbrot(env, pt);
	else if (env->fract_type == 2)
		ft_julia(env, pt);
}

void		mlximg_iter(t_window *env)
{
	int x;
	int y;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			pt = ft_point(x, y);
			ft_draw_pt(pt, env);
			x++;
		}
		y++;
	}
}

void		env_process_image(t_window *env)
{
	if (env->fract_type == 1)
		env->fractal = mandelbrot_new(env);
	else if (env->fract_type == 2)
		env->fractal = julia_new(env);
	mlximg_iter(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);

}
