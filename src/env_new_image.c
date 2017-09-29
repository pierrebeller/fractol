#include "fractol.h"

void	set_new_image(t_window *env)
{
	env->img = mlx_new_image(env->mlx, WIN_W, WIN_H);
}