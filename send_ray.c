/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 18:27:52 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/05 17:33:33 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void				print_debug(t_line *current, t_point *solution)
{
	// debugging
	printf("looking between (%f, %f) and (%f, %f)... "
			   , current->first.x, current->first.y
			   , current->second.x, current->second.y);
	printf("solution = (%f, %f)\t", solution->x, solution->y);
	printf("distance = %f\n", distance_between(&current->first, solution));
}

static int			map_offset(double coordinate)
{
	double			compare;

	compare = coordinate - .5 - floor(coordinate);
	if (compare < 0)
		return (-1);
	if (compare > 0)
		return (1);
	return (0);
}

static void			set_vertical(t_ray *ray, t_map *map, t_line *current
										, double direction)
{
	t_point			solution;

	solution.x = floor(current->second.x - .5) + .5 + (direction > M_PI);
	solution.y = ((current->second.y - current->first.y)
							/ (current->second.x - current->first.x))
					* (solution.x - current->first.x) + current->first.y;
	if (solution.y <= GREATER(current->first.y, current->second.y)
		&& solution.y >= SMALLER(current->first.y, current->second.y)
		&& map->data[(int)solution.y][(int)solution.x]
		&& map->data[(int)solution.y + map_offset(solution.y)][(int)solution.x])
	{
		ray->distance = distance_between(&current->first, &solution);
		ray->color = direction < M_PI ? EAST : WEST;
	}
}

static void			set_horizontal(t_ray *ray, t_map *map, t_line *current
										, double direction)
{
	t_point			solution;

	solution.y = floor(current->second.y - .5) + .5
		+ (direction > M_PI_2 && direction < M_PI + M_PI_2);
	solution.x = ((current->second.x - current->first.x)
							/ (current->second.y - current->first.y))
					* (solution.y - current->first.y) + current->first.x;
	(void)map;
	if (solution.x <= GREATER(current->first.x, current->second.x)
		&& solution.x >= SMALLER(current->first.x, current->second.x)
		&& map->data[(int)solution.x][(int)solution.y]
		&& map->data[(int)solution.y][(int)solution.x + map_offset(solution.x)])
	{
		ray->distance = distance_between(&current->first, &solution);
		ray->color = (direction > M_PI + M_PI_2 || direction < M_PI_2)
							? NORTH : SOUTH;
	}
}

static int			iterate_line(t_map *map, t_line *line, double direction)
{
	line->second.x += sin(direction);
	line->second.y += cos(direction);
	return (is_on_map(map, &line->second));
}

static void			set_ray(t_ray *ray, t_ray *vertical, t_ray *horizontal)
{
	if (vertical->distance != -1 && horizontal->distance != -1)
		*ray = vertical->distance < horizontal->distance
			? *vertical : *horizontal;
	else if (vertical->distance != -1)
		*ray = *vertical;
	else if (horizontal->distance != -1)
		*ray = *horizontal;
	else
		ray->distance = -1;
}

void				send_ray(t_ray *ray, t_map *map, t_point *location
								, double direction)
{
	t_line			current;
	t_ray			vertical;
	t_ray			horizontal;

	/* printf("direction =  %f (%f degrees)\n", direction */
	/* 		, radians_to_degrees(direction)); */
	current.first = *location;
	current.second = current.first;
	vertical.distance = -1;
	horizontal.distance = -1;
	while (iterate_line(map, &current, direction)
			&& vertical.distance == -1 && horizontal.distance == -1)
	{
		if (direction != 0 && direction != M_PI)
			set_vertical(&vertical, map, &current, direction);
		if (direction != M_PI_2 && direction != M_PI + M_PI_2)
			set_horizontal(&horizontal, map, &current, direction);
	}
	set_ray(ray, &vertical, &horizontal);
	/* printf("ray->distance = %f\n", ray->distance); */
}
