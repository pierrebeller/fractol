/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 14:08:08 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/02 14:08:11 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				get_psychedelic_color(int i, t_window *env)
{
	int		color;

	color = get_rgb_color(env->mouse_pos->x % 50 * i,\
		env->mouse_pos->y % 150 * i,\
		(env->mouse_pos->x + env->mouse_pos->y) % 250 * i);
	return (color);
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

int				get_normal_color(int i)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	int				color;

	r = 50 * i;
	g = 0;
	b = 100 * i;
	color = (r << 16) + (g << 8) + b;
	return (color);
}

int				choose_color(int i, t_window *env)
{
	if (env->color == 1)
		return (get_normal_color(i));
	else
		return (get_psychedelic_color(i, env));
}
