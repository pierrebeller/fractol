#include "fractol.h"

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
	else 
		error_usage();
}

void		proceed(char *arg)
{
	t_window *env;

	env = set_env();
	fractal_choice(env, arg);
	set_new_image(env);
	ft_set_hook(env);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		proceed(argv[1]);
	else
		error_usage();
	return (0);
}