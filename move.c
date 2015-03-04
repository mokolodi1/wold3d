/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 15:59:15 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/04 23:04:13 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void				move(double x, double y, t_environment *env)
{
	env->camera.location.x += VELOCITY * x;
	env->camera.location.y += VELOCITY * y;
	printf("camera location now (%f, %f)\n", env->camera.location.x
		   , env->camera.location.y);
	draw(env);
}
