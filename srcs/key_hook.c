/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 13:53:27 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/16 15:06:24 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void			switch_keys(int keycode, t_environment *env)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_W || keycode == KEY_UP_ARROW)
		move_camera(sin(env->camera.direction)
					, cos(env->camera.direction), env);
	else if (keycode == KEY_A || keycode == KEY_LEFT_ARROW)
		move_camera(sin(env->camera.direction - M_PI_2)
					, cos(env->camera.direction - M_PI_2), env);
	else if (keycode == KEY_S || keycode == KEY_DOWN_ARROW)
		move_camera(-sin(env->camera.direction)
					, -cos(env->camera.direction), env);
	else if (keycode == KEY_D || keycode == KEY_RIGHT_ARROW)
		move_camera(sin(env->camera.direction + M_PI_2)
					, cos(env->camera.direction + M_PI_2), env);
	else if (keycode == KEY_PERIOD || keycode == KEY_E)
		rotate_camera(env, ANGULAR_VELOCITY);
	else if (keycode == KEY_COMMA || keycode == KEY_Q)
		rotate_camera(env, -ANGULAR_VELOCITY);
}

int					key_hook(int keycode, t_environment *env)
{
	(void)env;
	ft_printf("key: %d\n", keycode);
	switch_keys(keycode, env);
	return (0);
}
