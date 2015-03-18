/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 15:59:15 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/05 15:56:59 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void				move_camera(double x, double y, t_environment *env)
{
	double			possible_x;
	double			possible_y;

	possible_x = env->camera.location.x + VELOCITY * x;
	possible_y = env->camera.location.y + VELOCITY * y;
	if (possible_x < env->map->width - 1 && possible_x >= 0)
		env->camera.location.x = possible_x;
	else
		env->camera.location.x = (possible_x < 0 ? 0 : env->map->width);
	if (possible_y < env->map->height - 1 && possible_y >= 0)
		env->camera.location.y = possible_y;
	else
		env->camera.location.y = (possible_y < 0 ? 0 : env->map->height);
	printf("camera location now (%f, %f)\n", env->camera.location.x
		   , env->camera.location.y);
	draw(env);
}
