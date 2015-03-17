/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 18:27:52 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/17 16:42:23 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** set_vertical = finds walls that are vertical on the map
*/

static void			set_vertical(t_ray *ray, t_map *map, t_point *start
								 , double angle)
{
	int				current_x;
	int				delta_x;
	double			current_y;
	double			delta_y;

	delta_x = ((angle < M_PI_2 || angle > M_PI_2 + M_PI) ? 1 : -1);
	delta_y = -sin(angle) / cos(angle) * delta_x;
	if (start->x < 0 || start->x > map->width)
		current_x = (start->x < 0 ? 0 : map->width);
	else
		current_x = floor(start->x) + (delta_x == 1);
	current_y = start->y + delta_y * ft_abs_double(current_x - start->x);
	if ((start->x < 0 || start->x > map->width)
			&& (current_y < 0 || current_y > map->height))
		return ;
	while ((delta_x == 1 ? current_x < map->width : current_x >= 0)
		   && (delta_y > 0 ? current_y <= map->height : current_y >= 0))
	{
		if (map->data[(int)floor(current_y)][current_x]
			&& map->data[(int)floor(current_y + 1)][current_x])
		{
			ray->distance = DISTANCE(start->x, start->y, current_x, current_y);
			ray->direction = (delta_x == 1 ? EAST : WEST);
			return ;
		}
		current_y += delta_y;
		current_x += delta_x;
	}
}

static void			set_horizontal(t_ray *ray, t_map *map, t_point *start
								 , double angle)
{
	(void)ray;
	(void)map;
	(void)start;
	(void)angle;
}

void				send_ray(t_ray *ray, t_map *map, t_point *location
										, double viewing_angle)
{
	t_ray			vertical;
	t_ray			horizontal;

	vertical.distance = -1;
	horizontal.distance = -1;
	if (sin(viewing_angle))
		set_vertical(&vertical, map, location, viewing_angle);
	if (cos(viewing_angle))
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
