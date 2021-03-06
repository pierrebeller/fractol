/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:59:58 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/08 17:35:50 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

void		fractal_choice(t_window *env, char *arg)
{
	if (arg == NULL)
		error_usage();
	else if (ft_strequ(arg, "mandelbrot"))
		env->fractal_type = 1;
	else if (ft_strequ(arg, "julia"))
		env->fractal_type = 2;
	else if (ft_strequ(arg, "ship"))
		env->fractal_type = 3;
	else if (ft_strequ(arg, "mandelbar"))
		env->fractal_type = 4;
	else if (ft_strequ(arg, "julia_sin"))
		env->fractal_type = 5;
	else if (ft_strequ(arg, "test"))
		env->fractal_type = 6;
	else
		error_usage();
}

void		set_fractal(t_window *env)
{
	if (env->fractal_type == 2 || env->fractal_type == 5)
		env->fractal = julia_new(env);
	else 
		env->fractal = mandelbrot_new(env);
}

void		proceed(char *arg)
{
	t_window *env;

	env = set_env();
	fractal_choice(env, arg);
	set_fractal(env);
	ft_set_hooks(env);
	mlx_loop(env->mlx);
}

int			main(int argc, char **argv)
{
	if (argc == 2)
		proceed(argv[1]);
	else
		error_usage();
	return (0);
}
