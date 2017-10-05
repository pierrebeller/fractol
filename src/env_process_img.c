/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_process_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:58:51 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/01 15:58:53 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

void		draw_pt(t_point *pt, t_window *env)
{
	int	color;

	color = 0;
	pt->x += env->offset.x;
	pt->y += env->offset.y;
	if (env->fractal_type == 1)
		color = ft_mandelbrot(env, pt);
	else if (env->fractal_type == 2)
		color = ft_julia(env, pt);
	else if (env->fractal_type == 3)
		color = ft_ship(env, pt);
	else if (env->fractal_type == 4)
		color = ft_mandelbar(env, pt);
	else if (env->fractal_type == 5)
		color = ft_julia_sin(env, pt);
	pt->x -= env->offset.x;
	pt->y -= env->offset.y;
	if (check_x(pt->x) && check_y(pt->y))
		ft_memcpy(&env->data[(pt->x * 4) + (pt->y * env->size)], (const void *)&(color), (size_t)(sizeof(int)));
}

void		mlximg_iter(t_window *env)
{
	int 	x;
	int 	y;
	t_point *pt;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			pt = ft_point(x, y);
			draw_pt(pt, env);
			free(pt);
			x++;
		}
		y++;
	}
}

void		env_process_image(t_window *env)
{
	if (env->fractal_type == 1)
		env->fractal = mandelbrot_new(env);
	else if (env->fractal_type == 2 || env->fractal_type == 5)
		env->fractal = julia_new(env);
	else 
		env->fractal = mandelbrot_new(env);
	mlximg_iter(env);
}
