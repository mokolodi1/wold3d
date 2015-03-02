/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_for_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 13:39:34 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/02 13:51:27 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int			point_is_on_line(t_point *point, t_line *line)
{
	return (point->x > SMALLER(line->first.x, line->second.x)
			&& point->x < GREATER(line->first.x, line->second.x)
			&& point->y > SMALLER(line->first.y, line->second.y)
			&& point->y < GREATER(line->first.y, line->second.y));
}

static void			set_points(t_point *to_vertical, t_point *to_horizontal
								   , t_camera *camera, t_line *view)
{
	to_vertical->x = ((int)camera->location.x) + .5;
	to_vertical->y = view->second.y - ((view->second.x - to_vertical->x)
											* (view->second.y - view->first.y))
								/ (view->second.x - view->first.x);
	to_horizontal->y = ((int)camera->location.y) + .5;
	to_horizontal->x = view->second.x - ((view->second.y - to_horizontal->y)
											* (view->second.x - view->first.x))
								/ (view->second.y - view->first.y);
}

int					look_for_walls(t_map *map, t_camera *camera, t_line *view)
{
	t_point			to_vertical;
	t_point			to_horizontal;
	double			vertical_length;
	double			horizontal_length;

	// check to make sure there are walls when we set the points
	(void)map;
	set_points(&to_vertical, &to_horizontal, camera, view);
	vertical_length = /* map->data[camera->location.y + vertical_wall_direction] */
		/* [camera->location.x + horizontal_wall_direction] */
		point_is_on_line(&to_vertical, view)
		? distance_between(&view->first, &to_vertical) : -1;
	horizontal_length = point_is_on_line(&to_horizontal, view)
		? distance_between(&view->first, &to_horizontal) : -1;
	if (vertical_length != -1)
	{
		if (horizontal_length != -1)
			view->second = vertical_length > horizontal_length
								? to_vertical : to_horizontal;
		else
			view->second = to_vertical;
		return (1);
	}
	if (horizontal_length != -1)
	{
		view->second = to_horizontal;
		return (1);
	}
	return (0);
}
