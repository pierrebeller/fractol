#include "fractol.h"
#include <stdlib.h>
#include <stdio.h>


t_mandelbrot 	ft_new_complex(int x, int y, t_window *env)
{
	t_mandelbrot complex;

	complex.x1 = -2 + env->x_move;
	complex.x2 = 0.5 + env->x_move;
	complex.y1 = -1.25 + env->y_move;
	complex.y2 = 1.25 + env->y_move;
	complex.cr = x / (WIN_W / (complex.x2 - complex.x1)) + complex.x1;
	complex.ci = y / (WIN_H / (complex.y2 - complex.y1)) + complex.y1;
	complex.zr = 0;
	complex.zi = 0;
	return (complex);
}

int				get_rgb_color(int r, int g, int b)
{
	int result;

	result = 0;
	result += r << 16;
	result += g << 8;
	result += b;
	return (result);
}

int				ft_draw_mandel(int x, int y, t_window *env)
{
	int color;
	int i;
	t_mandelbrot complex;
	long double tmp;
	int max;

	max = env->i_max;
	complex = ft_new_complex(x, y, env);
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
	color = get_rgb_color(env->x_mouse % 50 * i, env->y_mouse % 150 * i, (env->x_mouse + env->y_mouse) % 250 * i);
	return (color);
}

void			ft_mandelbrot(t_window *env)
{
	int x;
	int y;
	int color;

	x = 0;
	y = 0;
	(void)env;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			color = ft_draw_mandel(x, y, env);
			ft_memcpy(&env->data[(x * 4) + (y * env->size)], (const void *)&(color), (size_t)(sizeof(int)));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}

int		key_hook(int keycode, t_window *env)
{
	if (keycode == 53)
	{
		mlx_clear_window(env->mlx, env->win);
		exit(0);
	}
	if (keycode == 123)
	{
		env->x_move += 0.05;
		ft_mandelbrot(env);
	}
	if (keycode == 124)
	{
		env->x_move -= 0.05;
		ft_mandelbrot(env);
	}
	if (keycode == 125)
	{
		env->y_move -= 0.05;
		ft_mandelbrot(env);
	}
	if (keycode == 126)
	{
		env->y_move += 0.05;
		ft_mandelbrot(env);
	}
	printf("%d\n", keycode);
	return (0);
}

int				env_mousemove_hook(int x, int y, t_window *env)
{
	env->x_mouse = x;
	env->y_mouse = y;
	ft_mandelbrot(env);
	return (0);
}

// int				mouse_scrolling(int button, int x, int y, t_env *env)
// {
// 	t_twl_dpoint	pos;
// 	t_twl_dpoint	tmp;

// 	env->is_rendering = 0;
// 	pos = (t_twl_dpoint){.x=env->offset_x + x, .y=env->offset_y + y};
// 	tmp = (t_twl_dpoint){.x=pos.x / env->mouse_zoom, .y=pos.y / env->mouse_zoom};
// 	if (button == 4)
// 		env->mouse_zoom *= 1.05;
// 	else if (button == 5)
// 		env->mouse_zoom *= 0.95;
// 	if (env->mouse_zoom > MAX_ZOOM)
// 		env->mouse_zoom = MAX_ZOOM;
// 	if (env->mouse_zoom <= 0.1)
// 		env->mouse_zoom = 0.1;
// 	env->offset_x += (tmp.x - (pos.x / env->mouse_zoom)) * env->mouse_zoom;
// 	env->offset_y += (tmp.y - (pos.y / env->mouse_zoom)) * env->mouse_zoom;
// 	env->i_max = env->mouse_zoom + INITIAL_LOOP;
// 	return (0);
// }

void			ft_new_window(t_window *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIN_W, WIN_H, "fractol");
	env->img = mlx_new_image(env->mlx, WIN_W, WIN_H);
	env->data = mlx_get_data_addr(env->img, &(env->color), &(env->size), &(env->endian));
	env->zoom = 100;
	env->i_max = INITIAL_LOOP;
}

int				main()
{
	t_window *env;

	env = (t_window *)malloc(sizeof(t_window));
	ft_new_window(env);
	ft_mandelbrot(env);
	mlx_key_hook(env->win, key_hook, env);
	mlx_hook(env->win, 6, 1 << 6, &env_mousemove_hook, env);
	// mlx_mouse_hook(env->win, mouse_scrolling, env);
	mlx_loop(env->mlx);
}

