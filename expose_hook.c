#include "wolf3d.h"

int					expose_hook(t_environment *env)
{
	draw(env);
	return (0);
}
