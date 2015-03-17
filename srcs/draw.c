/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 10:23:12 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/17 12:15:51 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int			get_color(t_direction direction)
{
	if (direction == EAST)
		return (mlx_rgb_to_color(255, 0, 0));
	if (direction == NORTH)
		return (mlx_rgb_to_color(0, 255, 0));
	if (direction == WEST)
		return (mlx_rgb_to_color(0, 0, 255));
	if (direction == SOUTH)
		return (mlx_rgb_to_color(255, 255, 0));
	return (mlx_rgb_to_color(255, 255, 255));
}

static int			convert_to_pixels(double distance)
{
	return ((atan(((double)SCOPE / 2) / distance) / DEGREE)
			* 5 / 200 * WINDOW_HEIGHT);
}

static void			draw_segment(t_environment *env, int x_pixel
									, double direction)
{
	t_ray			ray;
	int				wall_height;
	int				i;

	send_ray(&ray, env->map, &env->camera.location, direction);
	wall_height = ray.distance == -1 ? 0 : convert_to_pixels(ray.distance);
	i = 0;
	while (i < env->window_height)
	{
		if (ft_abs(env->window_height / 2 - i) < wall_height / 2)
			mlx_pixel_put(env->mlx, env->window, x_pixel, i
							, get_color(ray.direction));
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

	increment = VIEW_WIDTH / env->window_width;
	direction = env->camera.direction + VIEW_WIDTH / 2
		- increment / 2;
	i = 0;
	while (i < env->window_width)
	{
		normalize_angle(&direction);
		draw_segment(env, i, direction);
		direction -= increment;
		i++;
	}
}
