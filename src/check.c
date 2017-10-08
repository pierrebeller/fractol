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
#include <stdlib.h>

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

void	ft_destroy_map(t_window *env)
{
	int		i;
	int		j;
	t_point	***map;

	i = 0;
	map = env->map;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != NULL)
		{
			free(map[i][j]);
			j++;
		}
		free(map[i][j]);
		free(map[i]);
		i++;
	}
	free(map[i]);
}

void	ft_quit(t_window *env)
{
	mlx_destroy_image(env->mlx, env->img);
	mlx_destroy_window(env->mlx, env->win);
	ft_destroy_map(env);
	free(env->map);
	free(env->mouse_pos);
	free(env->fractal->p1);
	free(env->fractal->p2);
	free(env->fractal->zoom);
	free(env->fractal);
	free(env);
	exit(0);
}
