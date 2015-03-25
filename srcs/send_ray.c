/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 18:27:52 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/25 11:40:17 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** set_vertical = finds walls that are vertical on the map
** set_horizontal = finds walls that are horizontal on the map
*/

/*
** I could make this more optimized (do both loops in the same
** function or something), but this is very easy to understand and
** runs without a problem.
*/

static void			set_vertical(t_ray *ray, t_map *map, t_point *start
									, double angle)
{
	int				current_x;
	int				delta_x;
	double			current_y;
	double			delta_y;

	delta_x = (POINTS_RIGHT(angle) ? 1 : -1);
	delta_y = -sin(angle) / cos(angle) * delta_x;
	if (start->x < 0 || start->x > map->width)
		current_x = (start->x < 0 ? 0 : map->width);
	else
		current_x = floor(start->x) + (delta_x == 1);
	current_y = start->y + delta_y * ft_abs_double(current_x - start->x);
	while (current_x < map->width && current_x >= 0
			&& current_y < map->height - 1 && current_y >= 0)
	{
		if (map->data[(int)floor(current_y)][current_x]
			&& map->data[(int)floor(current_y + 1)][current_x])
		{
			ray->distance = DISTANCE(start->x, start->y, current_x, current_y);
			ray->color = (delta_x == 1 ? COLOR_GREEN : COLOR_BLUE);
			return ;
		}
		current_y += delta_y;
		current_x += delta_x;
	}
}

static void			set_horizontal(t_ray *ray, t_map *map, t_point *start
									, double angle)
{
	int				current_y;
	int				delta_y;
	double			current_x;
	double			delta_x;

	delta_y = (POINTS_DOWN(angle) ? 1 : -1);
	delta_x = -cos(angle) / sin(angle) * delta_y;
	if (start->y < 0 || start->y > map->height)
		current_y = (start->y < 0 ? 0 : map->height);
	else
		current_y = floor(start->y) + (delta_y == 1);
	current_x = start->x + delta_x * ft_abs_double(current_y - start->y);
	while (current_y < map->height && current_y >= 0
			&& current_x < map->width - 1 && current_x >= 0)
	{
		if (map->data[current_y][(int)floor(current_x)]
			&& map->data[current_y][(int)floor(current_x + 1)])
		{
			ray->distance = DISTANCE(start->y, start->x, current_y, current_x);
			ray->color = (delta_y == 1 ? COLOR_RED : COLOR_YELLOW);
			return ;
		}
		current_x += delta_x;
		current_y += delta_y;
	}
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
		*ray = (vertical.distance < horizontal.distance
				? vertical : horizontal);
	else if (vertical.distance != -1)
		*ray = vertical;
	else if (horizontal.distance != -1)
		*ray = horizontal;
	else
		ray->distance = -1;
}
