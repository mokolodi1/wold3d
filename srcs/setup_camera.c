/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 22:00:05 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/25 15:21:16 by tfleming         ###   ########.fr       */
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

static void			set_to_zero(int *first, int *second)
{
	*first = 0;
	*second = 0;
}

static void			if_unset_put_in_middle(t_camera *camera, t_map *map
											, int *found)
{
	// possible case where we try to put the camera where there's a wall
	if (!*found)
	{
		set_camera_location(camera, ((double)(map->width - 1)) / 2
							, ((double)(map->height - 1)) / 2, found);
	}
}

void				setup_camera(t_camera *camera, t_map *map)
{
	int				x;
	int				y;
	int				found;

	set_to_zero(&found, &y);
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->data[y][x] == 2)
			{
				set_camera_location(camera, x, y, &found);
				map->data[y][x] = 0;
			}
			x++;
		}
		y++;
	}
	if_unset_put_in_middle(camera, map, &found);
	camera->direction = M_PI_2;
}
