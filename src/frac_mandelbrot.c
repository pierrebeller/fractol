/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:59:37 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/01 15:59:39 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mandelbrot(t_window *env, t_point *pt)
{
	int			color;
	int			i;
	t_complex	complex;
	double		tmp;
	int			max;

	max = env->i_max;
	complex = new_mandel_complex(pt, env->fractal);
	i = 0;
	while (1)
	{
		tmp = complex.z.r;
		complex.z.r = complex.z.r * complex.z.r - complex.z.i\
		* complex.z.i + complex.c.r;
		complex.z.i = 2 * complex.z.i * tmp + complex.c.i;
		i++;
		if (((complex.z.r * complex.z.r + complex.z.i\
			* complex.z.i) >= 4) || i >= max)
			break ;
	}
	color = choose_color(i, env);
	return (color);
}
