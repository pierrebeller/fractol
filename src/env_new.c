#include <stdlib.h>
#include "fractol.h"

t_window	*set_env(void)
{
	t_window *env;

	env = (t_window *)malloc(sizeof(t_window));
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIN_W, WIN_H, "fractol");
	env->data = mlx_get_data_addr(env->img, &(env->color), &(env->size), &(env->endian));
	env->zoom = 1;
	env->i_max = INITIAL_LOOP;
	env->is_rendering = 0;
	env->offset.x = 0;
	env->offset.y = 0;
	env->mouse_pos = ft_point_init(WIN_W / 2, WIN_H / 2);
	env->mouse_zoom = 1.0;
	env->mouse_zoom_pos.x = 0;
	env->mouse_zoom_pos.y = 0;
	return (env);
}
