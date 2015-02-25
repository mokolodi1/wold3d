#include "wolf3d.h"

static void			setup_camera(t_camera *camera)
{
	camera->location->x = 0;
	camera->locatoin->y = 0;
	camera->horizontal_viewing_angle = 90;
	camera->vertical_viewing_angle = 90;
}

static void			setup_environment(t_environment *env, t_map *map)
{
	env->mlx = mlx_init();
	env->window_width = DEFAULT_WINDOW_WIDTH;
	env->window_height = DEFAULT_WINDOW_HEIGHT;
	env->window = mlx_new_window(env->mlx
									, env->window_width, env->window_height
									, "wolf3d");
	env->map = map;
	setup_camera(&env->camera);
}

void				setup_viewer(t_map *map)
{
	t_environment	env;

	setup_environment(&env, map);
	mlx_expose_hook(env.window, expose_hook, &env);
	mlx_key_hook(env.window, key_hook, &env);
	mlx_loop(env.mlx);
}
