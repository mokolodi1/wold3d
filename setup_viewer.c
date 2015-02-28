#include "wolf3d.h"

static void			setup_camera(t_camera *camera, t_map *map)
{
	camera->location.x = ((double)map->width) / 2;
	camera->location.y = ((double)map->height) / 2;
	camera->direction = 0;
	set_wall_directions(camera);
	camera->horizontal_viewing_angle = degrees_to_radians(180);
	camera->vertical_viewing_angle = degrees_to_radians(90);
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
	setup_camera(&env->camera, map);
}

void				setup_viewer(t_map *map)
{
	t_environment	env;

	setup_environment(&env, map);
	mlx_expose_hook(env.window, expose_hook, &env);
	mlx_key_hook(env.window, key_hook, &env);
	//draw(&env);
	mlx_loop(env.mlx);
}
