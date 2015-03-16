/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 18:27:52 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/16 20:14:29 by tfleming         ###   ########.fr       */
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
	double			delta_y;
	int				delta_x;

	fprintf(stdout, "\n\nset_vertical viewing_angle = %f degrees\n"
			, RADIANS_TO_DEGREES(viewing_angle));
	delta_x = (viewing_angle < M_PI ? 1 : -1);
	delta_y = - cos(viewing_angle) / sin(viewing_angle);
	current.x = floor(start->x) + (viewing_angle < M_PI);
	current.y += delta_y * (viewing_angle < M_PI
				? (start->x - floor(start->x)) : (ceil(start->x) - start->x));
	fprintf(stdout, "start = (%f, %f)\t", start->x, start->y);
	fprintf(stdout, "current = (%f, %f)\t", current.x, current.y);
	fprintf(stdout, "deltas = (%d, %f)\t", delta_x, delta_y);
	fprintf(stdout, "\n");
	while ((viewing_angle < M_PI ? current.x >= 4 : current.x <= map->width)
		   && current.y >= 0 && current.y <= map->width)
	{
		if (map->data[(int)current.y][(int)current.x])
		{
			ray->distance = distance_between(start, &current);
			ray->direction = (current.y - floor(current.y) > 0 ? NORTH : SOUTH);
			fprintf(stdout, "found wall (distance = %f)\n", ray->distance);
			return ;
		}
		fprintf(stdout, "moving along... now at (%f, %f)\t"
				, current.x, current.y);
		current.y += delta_y;
		current.x += delta_x;
	}
	fprintf(stdout, "none found\n");
}

static void			set_horizontal(t_ray *ray, t_map *map, t_point *start
								 , double viewing_angle)
{
	(void)ray;
	(void)map;
	(void)start;
	(void)viewing_angle;
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
		*ray = (vertical.distance < horizontal.distance ? vertical: horizontal);
	else if (vertical.distance != -1)
		*ray = vertical;
	else if (horizontal.distance != -1)
		*ray = horizontal;
	else
		ray->distance = -1;
}
