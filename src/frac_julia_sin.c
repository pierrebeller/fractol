/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_julia_sin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 19:04:53 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/05 19:04:54 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol.h"

int		ft_julia_sin(t_window *env, t_point *pt)
{
	t_complex	complex;
	int			color;
	double		i;
	double		max;
	double		tmp;

	i = 0;
	max = env->i_max;
	complex = complex_julia_sin_new(env, pt, env->fractal);
	while (1)
	{
		tmp = complex.z.r;
		complex.z.r = complex.z.r * complex.z.r * complex.z.r - 3 *
						(complex.z.r * complex.z.i * complex.z.i) + complex.c.r;
		complex.z.i = 3 * ((tmp * tmp) * complex.z.i) - complex.z.i *
										complex.z.i * complex.z.i + complex.c.i;
		i++;
		if (((complex.z.r * complex.z.r + complex.z.i * complex.z.i) >= 4)
																	|| i >= max)
			break ;
	}
	color = choose_color(i, env);
	return (color);
}
