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
** set_vertical = finds walls that are vertical on the map
*/

static void			set_vertical(t_ray *ray, t_map *map, t_point *start
								 , double viewing_angle)
{
	t_point			current;
	int				delta_y;
	int				delta_x;

	current.x = math.floor(start->current.x) + (viewing_angle < M_PI);
	delta_x = (viewing_angle < M_PI ? 1 : -1);
	delta_y = sin(viewing_angle) / cos(viewing_angle);
	y += delta_y * (viewing_angle < M_PI
					? (start->x - floor(start->x) : (ceil(start->x) - start->x)));
	while ((viewing_angle < M_PI ? current.x >= 4 : current.x <= map->width)
		   && y >= 0 && y <= map->width)
	{
		if (map->data[(int)y][current.x]
			&& map[/* stuff */][current.x])
		{
			ray->distance = distance_between(start, current);
			ray->direction = (current.y - floor(current.y) > 0 ? NORTH : SOUTH);
			return ;
		}
		y += delta_y;
		current.x += delta_x;
	}
}

void				send_ray(t_ray *ray, t_map *map, t_point *location
										, double viewing_angle)
{
	t_ray			vertical;
	t_ray			horizontal;

	vertical.distance = -1;
	horizontal.distance = -1;
	if (cos(viewing_angle))
		set_vertical(&vertical, map, location, viewing_angle);
	if (sin(viewing_angle))
		set_horizontal(&horizontal, map, location, viewing_angle);
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
