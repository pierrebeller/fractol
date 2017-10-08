/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:59:13 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/01 15:59:15 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	error_usage(void)
{
	ft_putstr("usage: ./fractol [mandelbrot][julia][ship][mandelbar]\
		[julia_sin][test]\n");
	exit(1);
}
