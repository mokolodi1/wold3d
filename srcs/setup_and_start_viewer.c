/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_and_start_viewer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 13:53:46 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/20 17:35:46 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** camera starts facing towards top of map
*/

static void			set_camera_location(t_camera *camera, double x, double y
										, int *found)
{
	if (*found)
	{
		ft_printf("Multiple starting locations specified in map file.\n");
		exit(1);
	}
	else
	{
		camera->location.x = x;
		camera->location.y = y;
		*found = 1;
	}
}

static void			setup_camera(t_camera *camera, t_map *map)
{
	int				x;
	int				y;
	int				found;

	found = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->data[y][x] == 2)
			{
				set_camera_location(camera, x + .5, y + .5, &found);
				map->data[y][x] = 0;
			}
			x++;
		}
		y++;
	}
	if (!found)
	{
		set_camera_location(camera, (double)map->width / 2
							, (double)map->height / 2, &found);
		printf("setting at end\n");
	}
	camera->direction = M_PI_2;
	printf("camera location: (%f, %f)\n"
			, camera->location.x, camera->location.y);
}

static void			setup_environment(t_environment *env, t_map *map)
{
	env->mlx = mlx_init();
	env->window_width = WINDOW_WIDTH;
	env->window_height = WINDOW_HEIGHT;
	env->window = mlx_new_window(env->mlx
								, env->window_width
								, env->window_height
								, "wolf3d");
	env->map = map;
}

static void			setup_image(t_environment *env)
{
	t_image			*image;

	image = &env->image;
	image->mlx_image = mlx_new_image(env->mlx, env->window_width
										  , env->window_height);
	image->bits_per_pixel = 0;
	image->line_size = 0;
	image->endian = 0;
	image->data = (int*)mlx_get_data_addr(image->mlx_image
											, &image->bits_per_pixel
											, &image->line_size
											, &image->endian);
	ft_putstr("Image information:\n");
	ft_printf("bits per pixel = %d\n", image->bits_per_pixel);
	ft_printf("line_size      = %d\n", image->line_size);
	ft_printf("endian         = %d\n", image->endian);
}

void				setup_and_start_viewer(t_map *map)
{
	t_environment	env;

	setup_environment(&env, map);
	setup_image(&env);
	setup_camera(&env.camera, map);
	mlx_expose_hook(env.window, expose_hook, &env);
	mlx_hook(env.window, 2, 3, key_hook, &env);
	mlx_loop(env.mlx);
}
