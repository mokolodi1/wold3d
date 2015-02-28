#include "wolf3d.h"

void				draw_segment(t_environment *env, int x_pixel
									, double viewing_angle)
{
	int				wall_height;
	int				i;

	wall_height = get_wall_height(env->map, &env->camera, viewing_angle);
	printf("viewing_angle = %f\twall_height = %d\n", viewing_angle, wall_height);
	i = 0;
	while (i < env->window_height)
	{
		if (ft_abs(env->window_height / 2 - i) < wall_height / 2)
			mlx_pixel_put(env->mlx, env->window, x_pixel, i,
						  mlx_rgb_to_color(255, 255, 255));
		else
			mlx_pixel_put(env->mlx, env->window, x_pixel, i,
						  mlx_rgb_to_color(30, 30, 30));
		i++;
	}
}

void            	draw(t_environment *env)
{
	double			viewing_angle;
	double			increment;
	int				i;

	// no negative or more than 360 degrees
	viewing_angle = env->camera.direction
							- env->camera.horizontal_viewing_angle / 2;
	increment = env->camera.horizontal_viewing_angle / env->window_width;
	printf("location = (%f, %f)\n", env->camera.location.x, env->camera.location.y);
	printf("increment = %f\n", increment);
	i = 0;
	while (i < env->window_width)
	{
		draw_segment(env, i, viewing_angle);
		viewing_angle += increment;
		i++;
	}
}
