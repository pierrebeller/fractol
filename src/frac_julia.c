/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:59:28 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/01 15:59:30 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_julia(t_window *env, t_point *pt)
{
	t_complex	complex;
	int			color;
	double		i;
	double		max;
	double		tmp;

	max = env->i_max;
	i = 0;
	complex = new_julia_complex(env, pt, env->fractal);
	while (1)
	{
		tmp = complex.z.r;
		complex.z.r = complex.z.r * complex.z.r - complex.z.i * complex.z.i +
																	complex.c.r;
		complex.z.i = 2 * complex.z.i * tmp + complex.c.i;
		i++;
		if (((complex.z.r * complex.z.r + complex.z.i * complex.z.i) >= 4)
																	|| i >= max)
			break ;
	}
	/*color = get_rgb_color(env->mouse_pos->x % 50 * i, env->mouse_pos->y % 150 * i,\
		(env->mouse_pos->x + env->mouse_pos->y) % 250 * i);*/
	color = get_normal_color(i);
	return (color);
}
