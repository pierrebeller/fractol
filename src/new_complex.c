/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_complex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 16:00:05 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/01 16:00:07 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <stdlib.h>

t_complex	new_ship_complex(t_point *pt, t_fractol *fractal)
{
	t_complex	complex;

	complex.c = ft_dcomplex(0.45 + 2 * 1.7 * ((pt->x / fractal->zoom->x\
		+ fractal->p1->x)), 0.5 + 2 * 1.7 * ((pt->y / fractal->zoom->y +\
		fractal->p1->y)));
	complex.z = ft_dcomplex(0, 0);
	return (complex);
}

t_complex	new_mandel_complex(t_point *pt, t_fractol *fractal)
{
	t_complex	complex;

	complex.c = ft_dcomplex(pt->x / fractal->zoom->x + fractal->p1->x, pt->y /\
	fractal->zoom->y + fractal->p1->y);
	complex.z = ft_dcomplex(0, 0);
	return (complex);
}

t_complex	new_julia_complex(t_window *env, t_point *pt, t_fractol *fractal)
{
	t_complex	complex;

	if (env->block_julia == 0)
	{
		complex.c = ft_dcomplex(0.285 + (double)(env->mouse_pos->x /\
		(double)WIN_W), 0.01 + (double)(env->mouse_pos->y / (double)WIN_H));
	}
	else
		complex.c = ft_dcomplex(0.285 + (double)(env->last_mouse_x /\
		(double)WIN_W), 0.01 + (double)(env->last_mouse_y / (double)WIN_H));
	complex.z = ft_dcomplex(pt->x / fractal->zoom->x + fractal->p1->x,\
		pt->y / fractal->zoom->y + fractal->p1->y);
	return (complex);
}

t_complex	complex_julia_sin_new(t_window *e, t_point *pt, t_fractol *fractal)
{
	t_complex	complex;

	complex.c = ft_dcomplex(0.285 + (double)(e->mouse_pos->x /
		(double)WIN_W), 0.01 + (double)(e->mouse_pos->y / (double)WIN_H));
	complex.z = ft_dcomplex(pt->x / fractal->zoom->x + fractal->p1->x,
		pt->y / fractal->zoom->y + fractal->p1->y);
	return (complex);
}

t_complex	complex_test_new(t_point *pt, t_fractol *fractal)
{
	t_complex complex;

	complex.c = ft_dcomplex(pt->x / fractal->zoom->x + fractal->p1->x,\
		pt->y / fractal->zoom->y + fractal->p1->y);
	complex.z = ft_dcomplex(pt->x / fractal->zoom->x, pt->y / fractal->zoom->y);
	return (complex);
}
