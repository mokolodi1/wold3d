#include "wolf3d.h"

static int			get_map_data(t_map *map, t_point *point
									, int x_offset, int y_offset)
{
	// todo
	(void)map;
	(void)point;
}

void				look_for_walls(t_map *map, t_line *view
								   , double *distance_result)
{
	t_line			to_left_block;
	t_line			to_right_block;

	if (get_map_data(
}
