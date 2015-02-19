#include "wolf3d.h"

void				draw_segment(t_environment *env, int x_pixel
									, double viewing_angle)
{
	int				wall_height;
	int				i;

	// calculate wall_height
	wall_height = 4;
	i = 0;
	while (i < env->window_height)
	{
		
		if (ft_abs(env->window_height / 2 - i) < wall_height / 2)
			mlx_pixel_put(env->mlx, env->window, x_pixel, i,
						  mlx_rgb_to_color(255, 255, 255));
		else
			mlx_pixel_put(env->mlx, env->window, x_pixel, i,
						  mlx_rgb_to_color(0, 0, 0));
		i++;
	}
	(void)viewing_angle;
}

void            	draw(t_environment *env)
{
	double			viewing_angle;
	double			increment;
	int				i;

	viewing_angle = -env->camera.horizontal_viewing_angle;
	increment = env->camera.horizontal_viewing_angle / env->window_width;
	i = 0;
	while (i < env->window_width)
	{
		draw_segment(env, i, viewing_angle);
		viewing_angle += increment;
		i++;
	}
	// debug
    mlx_pixel_put(env->mlx, env->window, 4, 4, mlx_rgb_to_color(255, 255, 255));
}
