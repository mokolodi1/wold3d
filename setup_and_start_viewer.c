/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_and_start_viewer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 13:53:46 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/03 15:06:39 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void			setup_camera(t_camera *camera, t_map *map)
{
	camera->location.x = ((double)map->width) / 2;
	camera->location.y = ((double)map->height) / 2;
	camera->direction = 0;
}

static void			setup_environment(t_environment *env, t_map *map)
{
	env->mlx = mlx_init();
	env->window_width = DEFAULT_WINDOW_WIDTH;
	env->window_height = DEFAULT_WINDOW_HEIGHT;
	env->window = mlx_new_window(env->mlx
									, env->window_width, env->window_height
									, "wolf3d");
	env->map = map;
	setup_camera(&env->camera, map);
}

void				setup_and_start_viewer(t_map *map)
{
	t_environment	env;

	setup_environment(&env, map);
	mlx_expose_hook(env.window, expose_hook, &env);
	mlx_key_hook(env.window, key_hook, &env);
	mlx_loop(env.mlx);
}
