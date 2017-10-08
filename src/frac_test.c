/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 19:22:47 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/06 19:22:49 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

int		ft_test(t_window *env, t_point *pt)
{
	int			color;
	int			i;
	t_complex	complex;
	double		tmp;
	int			max;

	max = env->i_max;
	complex = complex_test_new(pt, env->fractal);
	i = 0;
	while (1)
	{
		tmp = complex.z.r;
		complex.z.r = tmp * tmp * tmp - 3 * tmp * complex.z.i * complex.z.i;
		complex.z.i = 3 * tmp * tmp * complex.z.r - complex.z.i\
		* complex.z.i * complex.z.i;
		complex.z.r = exp(complex.z.r) * cos(complex.z.i) + complex.c.r;
		complex.z.i = exp(complex.z.r) * sin(complex.z.i) + complex.c.i;
		i++;
		if (((complex.z.r * complex.z.r + complex.z.i\
			* complex.z.i) >= 4) || i >= max)
			break ;
	}
	color = choose_color(i, env);
	return (color);
}
