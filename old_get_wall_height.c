/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_height.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 13:39:38 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/03 10:37:16 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void			iterate_line(t_line *line, double direction_angle)
{
	line->second.x = line->second.x + cos(direction_angle);
	line->second.y = line->second.y + sin(direction_angle);
}

static int			is_on_map(t_map *map, t_point *point)
{
	// off by one error on upper bounds?
	return (point->x >= 0 && point->y >= 0
			&& point->x <= map->width && point->y <= map->height);
}

static int			convert_distance_to_pixel_height(double distance
														, t_camera *camera)
{
	// handle very small values --> could overflow int
	// not sure about the formula
	// magic numbers

	return ((atan(((double)100 / 2) / distance) / 0.0174532925)
		/ ((double)camera->horizontal_viewing_angle
		   / (double)500) * 2 - 27932);
}

int					get_wall_height(t_map *map, t_camera *camera
										, double viewing_angle)
{
	t_line			current;
	int				found;

	
	current.first.x = camera->location.x;
	current.first.y = camera->location.y;
	current.second = current.first;
	found = 0;
	while (!found)
	{
		iterate_line(&current, viewing_angle);
		if (!is_on_map(map, &current.second))
			break;
		found = look_for_walls(map, camera, &current);
	}
	if (found)
	{
		returning = (convert_distance_to_pixel_height(line_length(&current)
													, camera));
		return (returning);
	}
	return (0);
}
