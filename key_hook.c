/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 13:53:27 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/05 16:00:49 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void			switch_keys(int keycode, t_environment *env)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == 'w' || keycode == KEY_UP_ARROW)
		move_camera(sin(env->camera.direction)
					, cos(env->camera.direction), env);
	else if (keycode == 'a' || keycode == KEY_LEFT_ARROW)
		move_camera(sin(env->camera.direction - M_PI_2)
					, cos(env->camera.direction - M_PI_2), env);
	else if (keycode == 's' || keycode == KEY_DOWN_ARROW)
		move_camera(-sin(env->camera.direction)
					, -cos(env->camera.direction), env);
	else if (keycode == 'd' || keycode == KEY_RIGHT_ARROW)
		move_camera(sin(env->camera.direction + M_PI_2)
					, cos(env->camera.direction + M_PI_2), env);
	else if (keycode == '.' || keycode == 'e')
		rotate_camera(env, ANGULAR_VELOCITY);
	else if (keycode == ',' || keycode == 'q')
		rotate_camera(env, -ANGULAR_VELOCITY);
}

int					key_hook(int keycode, t_environment *env)
{
	(void)env;
	ft_putstr("key: ");
	ft_putnbr(keycode);
	ft_putstr("\n");
	switch_keys(keycode, env);
	return (0);
}
