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
	unsigned int r;
	unsigned int g;
	unsigned int b;
	int color;

	r = (255 - i);
	g = (255 - (i * 100));
	b = (255 - (i * 25));
	color = (r << 16) + (g << 8) + b;
	return (color);
}