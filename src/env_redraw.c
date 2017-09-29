#include "fractol.h"

void	env_redraw(t_env *env)
{
	env_process_image(env);
	env_print_image(env);
	env->is_rendering = 0;
}