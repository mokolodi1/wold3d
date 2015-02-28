#include "wolf3d.h"

double				distance_between(t_point *first, t_point *second)
{
	return (sqrt(pow(second->x - first->x, 2) + pow(second->y - first->y, 2)));
}
