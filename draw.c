/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 10:23:12 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/03 19:20:37 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int			get_color(t_direction direction)
{
	(void)direction;
	return (mlx_rgb_to_color(255, 255, 255));
}

static int			convert_to_pixels(double distance)
{
	return ((atan(((double)SCOPE / 2) / distance) / DEGREE)
		/ ((double)VIEW_WIDTH / DEFAULT_WINDOW_WIDTH) * 2);
}

static void			draw_segment(t_environment *env, int x_pixel
									, double direction)
{
	t_ray			ray;
	int				wall_height;
	int				i;

	send_ray(&ray, env->map, &env->camera.location, direction);
	wall_height = ray.distance == -1 ? 0 : convert_to_pixels(ray.distance);
	printf("wall_height = %d\n\n", wall_height);
	i = 0;
	while (i < env->window_height)
	{
		if (ft_abs(env->window_height / 2 - i) < wall_height / 2)
			mlx_pixel_put(env->mlx, env->window, x_pixel, i
							, get_color(ray.color));
		else
			mlx_pixel_put(env->mlx, env->window, x_pixel, i,
						  BACKGROUND_COLOR);
		i++;
	}
}

void            	draw(t_environment *env)
{
	double			direction;
	double			increment;
	int				i;

	increment = HORIZONTAL_VIEWING_ANGLE / env->window_width;
	direction = env->camera.direction - HORIZONTAL_VIEWING_ANGLE / 2
		+ increment / 2;
	i = 0;
	while (i < env->window_width)
	{
		normalize_angle(&direction);
		draw_segment(env, i, direction);
		direction += increment;
		i++;
	}
}
