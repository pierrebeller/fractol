/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 18:04:23 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/01 18:04:49 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

t_fractol	*mandelbrot_new(t_window *env)
{
	t_fractol	*fractal;

	fractal = (t_fractol *)malloc(sizeof(t_fractol));
	if (fractal == NULL)
		return (NULL);
	fractal->p1 = ft_dpoint(-2.1, -1.2);
	fractal->p2 = ft_dpoint(0.6, 1.2);
	fractal->zoom = ft_dpoint(WIN_H / (fractal->p2->x - fractal->p1->x) *\
		env->mouse_zoom, WIN_W / (fractal->p2->y - fractal->p1->y) *\
		env->mouse_zoom);
	return (fractal);
}
