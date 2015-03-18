/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 15:59:15 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/18 19:16:02 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void				move_camera(double x, double y, t_environment *env)
{
	double			possible_x;
	double			possible_y;

	possible_x = env->camera.location.x + VELOCITY * x;
	possible_y = env->camera.location.y + VELOCITY * y;
	if (possible_x < env->map->width - 1 - WALL_DISTANCE
			&& possible_x >= WALL_DISTANCE)
		env->camera.location.x = possible_x;
	else
		env->camera.location.x = (possible_x < WALL_DISTANCE
					? WALL_DISTANCE : env->map->width - 1 - WALL_DISTANCE);
	if (possible_y < env->map->height - 1 - WALL_DISTANCE
			&& possible_y >= WALL_DISTANCE)
		env->camera.location.y = possible_y;
	else
		env->camera.location.y = (possible_y < WALL_DISTANCE
					? WALL_DISTANCE : env->map->height - 1 - WALL_DISTANCE);
	printf("camera location now (%f, %f)\n", env->camera.location.x
		   , env->camera.location.y);
	draw(env);
}
