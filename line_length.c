#include "wolf3d.h"

double				line_length(t_line *line)
{
	return (distance_between(&line->first, &line->second));
}
