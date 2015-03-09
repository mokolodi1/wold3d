/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 18:27:52 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/09 15:45:39 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** vertical = finds walls that are vertical on the map
*/

static void			set_vertical(t_ray *ray, t_map *map, t_point start
								 , double slope)
{
	// check to see if slope is bad
	(void)ray;
	(void)map;
	(void)start;
}

void				send_ray(t_ray *ray, t_map *map, t_point *location
										, double viewing_angle)
{
	t_ray			vertical;
	t_ray			horizontal;

	vertical.distance = -1;
	horizontal.distance = -1;
	set_vertical(&vertical, map, location, slope);
	set_horizontal(&horizontal, map, location, 1/slope);
	if (vertical.distance != -1 && horizontal.distance != -1)
		*ray = vertical.distance < horizontal.distance
			? vertical, horizontal;
	else if (vertical->distance != -1)
		*ray = *vertical;
	else if (horizontal->distance != -1)
		*ray = *horizontal;
	else
		ray->distance = -1;
}
