/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 15:56:28 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/21 21:37:09 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void				rotate_camera(t_environment *env, double delta_angle)
{
	env->camera.direction += delta_angle;
	normalize_angle(&env->camera.direction);
	draw(env);
}
