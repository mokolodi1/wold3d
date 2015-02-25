#include "wolf3d.h"

void				iterate_line(t_line *line, double direction_angle)
{
	line->first = line->second;
	// todo: this
	//view->second->x = view->second->x + sin
	(void)line;
	(void)direction_angle;
}

int					convert_distance_to_pixel_height(double distance
														, t_camera *camera)
{
	(void)distance;
	return (8);
}

int					get_wall_height(t_map *map, t_camera *camera
										, double viewing_angle)
{
	t_line			view;
	double			distance;

	view->second->x = camera->location->x;
	view->second->y = camera->location->y;
	distance = -1;
	while (is_on_map(view->second) && distance == -1)
	{
		iterate_line(&view, viewing_angle);
		look_for_walls(map, &view, &distance);
	}
	if (distance = -1)
		ft_putendl_exit("You went out of bounds!");
	return (convert_distance_to_pixel_height(distance, camera));
}
