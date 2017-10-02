/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_set_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:59:05 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/01 15:59:07 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <stdlib.h>

int		loop_hook(void *param)
{
	t_window			*env;

	env = (t_window*)param;
	if (env->is_rendering == 0)
	{
		env_redraw(param);
		env->is_rendering = 1;
	}
	return (0);
}

int		env_mousemove_hook(int x, int y, t_window *env)
{
	env->mouse_pos->x = x;
	env->mouse_pos->y = y;
	if (env->fractal_type)
		env->is_rendering = 0;
	return (0);
}

int		mouse_scrolling(int button, int x, int y, t_window *env)
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
	env->i_max = env->mouse_zoom + INITIAL_LOOP;
	return (0);
}

int		key_hook(int key, t_window *env)
{
	if (key == 53)
		exit(1);
	if (key == 123)
		env->offset.x += 0.05;
	if (key == 124)
		env->offset.x -= 0.05;
	if (key == 125)
		env->offset.y -= 0.05;
	if (key == 126)
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
