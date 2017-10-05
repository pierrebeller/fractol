/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_mandelbar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 13:00:46 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/03 13:00:48 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mandelbar(t_window *env, t_point *pt)
{
	int color;
	int i;
	t_complex complex;
	double tmp;
	int max;

	max = env->i_max;
	complex = new_mandel_complex(pt, env->fractal);
	i = 0;
	while (1)
	{
		tmp = complex.z.r;
		complex.z.r = complex.z.i * complex.z.i - complex.z.r * complex.z.r + complex.c.r;
		complex.z.i = 2 * complex.z.i * tmp + complex.c.i;
		i++;
		if (((complex.z.r * complex.z.r + complex.z.i * complex.z.i) >= 4) || i >= max)
			break;
	}
	color = get_rgb_color(env->mouse_pos->x % 50 * i, env->mouse_pos->y % 150 * i,\
		(env->mouse_pos->x + env->mouse_pos->y) % 250 * i);
	//color = get_normal_color(i);
	return (color);
}
