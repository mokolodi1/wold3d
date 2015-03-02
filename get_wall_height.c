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

	(void)camera;
	return ((int)(1 / distance * 10));
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
		printf("viewing_angle = %f\tline_length = %f\n"
				, viewing_angle, line_length(&current));
		return (convert_distance_to_pixel_height(line_length(&current)
													, camera));
	}
	return (0);
}
