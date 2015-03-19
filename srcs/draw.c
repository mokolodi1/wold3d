/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 10:23:12 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/19 21:14:23 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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
	int				y_pixel;
	int				ceiling_part;

	send_ray(&ray, env->map, &env->camera.location, direction);
	wall_height = ray.distance == -1 ? 0 : convert_to_pixels(ray.distance);
	ceiling_part = (env->window_height - wall_height) / 2;
	y_pixel = 0;
	while (y_pixel < ceiling_part)
	{
		env->image.data[y_pixel * env->window_width + x_pixel] = COLOR_BLACK;
		y_pixel++;
	}
	while (y_pixel < wall_height + ceiling_part)
	{
		env->image.data[y_pixel * env->window_width + x_pixel] = ray.color;
		y_pixel++;
	}
	while (y_pixel < env->window_height)
	{
		env->image.data[y_pixel * env->window_width + x_pixel] = COLOR_BLACK;
		y_pixel++;
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
	mlx_put_image_to_window(env->mlx, env->window, env->image.mlx_image, 0, 0);
}
