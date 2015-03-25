/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 15:59:15 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/25 15:21:05 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void				move_camera(double angle, t_environment *env)
{
	t_point			possible;

	normalize_angle(&angle);
	possible.x = env->camera.location.x + VELOCITY * cos(-angle);
	possible.y = env->camera.location.y + VELOCITY * sin(-angle);
	if (possible.x > env->map->width - 1 - WALL_DISTANCE)
		possible.x = env->map->width - 1 - WALL_DISTANCE;
	else if (possible.x < WALL_DISTANCE)
		possible.x = WALL_DISTANCE;
	if (possible.y > env->map->height - 1 - WALL_DISTANCE)
		possible.y = env->map->height - 1 - WALL_DISTANCE;
	else if (possible.y < WALL_DISTANCE)
		possible.y = WALL_DISTANCE;
	env->camera.location = possible;
	draw(env);
}
