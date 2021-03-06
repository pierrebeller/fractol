/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_redraw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:58:57 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/01 15:58:59 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	env_redraw(t_window *env)
{
	env_process_image(env);
	env_print_image(env);
	env->is_rendering = 0;
}
