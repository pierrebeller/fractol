#include "fractol.h"
#include "libft.h"

int		loop_hook(void *param)
{
	t_env			*env;

	env = (t_env*)param;
	if (env->is_rendering = 0)
	{
		env_redraw(param);
		env->is_rendering = 1;
	}
	return (0);
}

int		env_mousemove_hook(int x, int y, t_env *env)
{
	env->mouse_pos->x = x;
	env->mouse_pos->y = y;
	if (env->fract_choice)
		env->is_rendering = 0;
	return (0);
}

int		mouse_scrolling(int button, int x, int y, t_env *env)
{
	t_dpoint	pos;
	t_dpoint	tmp;

	env->is_rendering = 0;
	pos = (t_dpoint){.x=env->offset.x + x, .y=env->offset.y + y};
	tmp = (t_dpoint){.x=pos.x / env->mouse_zoom, .y=pos.y /
															env->mouse_zoom};
	if (button == 4)
		env->mouse_zoom *= 1.05;
	else if (button == 5)
		env->mouse_zoom *= 0.95;
	if (env->mouse_zoom > MAX_ZOOM)
		env->mouse_zoom = MAX_ZOOM;
	if (env->mouse_zoom <= 0.1)
		env->mouse_zoom = 0.1;
	env->offset.x += (tmp.x - (pos.x / env->mouse_zoom)) * env->mouse_zoom;
	env->offset.y += (tmp.y - (pos.y / env->mouse_zoom)) * env->mouse_zoom;
	env->max_iter = env->mouse_zoom + INITIAL_LOOP;
	return (0);
}

int		key_hook(int key, t_env *env)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 123)
		env->offset.x += 0.05;
	if (keycode == 124)
		env->offset.x -= 0.05;
	if (keycode == 125)
		env->offset.y -= 0.05;
	if (keycode == 126)
		env->offset.y += 0.05;
	return (0);
}

void	ft_set_hooks(t_window *env)
{
	mlx_hook(env->win, 6, 1 << 6, &env_mousemove_hook, env);
	mlx_mouse_hook(env->win, mouse_scrolling, env);
	mlx_key_hook(env->win, key_hook, env);
	mlx_expose_hook(env->win, expose_hook, env);
	mlx_loop_hook(env->mlx, &loop_hook, env);
}