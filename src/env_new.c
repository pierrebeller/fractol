/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:58:31 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/01 15:58:33 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol.h"

t_point		**new_line(int y)
{
	t_point	**line;
	int		x;

	x = 0;
	line = (t_point **)malloc(sizeof(t_point *) * (WIN_W + 1));
	while (x < WIN_W)
	{
		line[x] = ft_point(x, y);
		x++;
	}
	line[x] = NULL;
	return (line);
}

t_point		***new_map(void)
{
	t_point	***map;
	int		y;

	y = 0;
	map = (t_point ***)malloc(sizeof(t_point **) * (WIN_H + 1));
	while (y < WIN_H)
	{
		map[y] = new_line(y);
		y++;
	}
	map[y] = NULL;
	return (map);
}

t_window	*set_env(void)
{
	t_window *env;

	env = (t_window *)malloc(sizeof(t_window));
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIN_W, WIN_H, "fractol");
	env->img = mlx_new_image(env->mlx, WIN_W, WIN_H);
	env->data = mlx_get_data_addr(env->img, &(env->color),\
		&(env->size), &(env->endian));
	env->zoom = 1;
	env->color = 1;
	env->i_max = INITIAL_LOOP;
	env->is_rendering = 0;
	env->offset.x = 0;
	env->offset.y = 0;
	env->mouse_pos = ft_point(WIN_W / 2, WIN_H / 2);
	env->block_julia = 0;
	env->mouse_zoom = 1.0;
	env->mouse_zoom_pos.x = 0;
	env->mouse_zoom_pos.y = 0;
	env->map = new_map();
	return (env);
}
