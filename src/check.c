/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 14:50:55 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/02 14:50:56 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		check_x(int x)
{
	if (x > 0 && x < WIN_W)
		return (1);
	return (0);
}

int		check_y(int y)
{
	if (y > 0 && y < WIN_H)
		return (1);
	return (0);
}

