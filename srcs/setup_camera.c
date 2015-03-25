/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 22:00:05 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/25 17:59:05 by tfleming         ###   ########.fr       */
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
	if (!*found)
	{
		if ((map->width % 2 == 1 && map->height % 2 == 1
				&& map->data[(map->height - 1) / 2][(map->width - 1) / 2])
			|| (map->width % 2 == 1
				&& map->data[(map->height - 1) / 2][(map->width - 1) / 2]
				&& map->data[(map->height - 1) / 2 + 1][(map->width - 1) / 2])
			|| (map->height % 2 == 1
				&& map->data[(map->height - 1) / 2][(map->width - 1) / 2]
				&& map->data[(map->height - 1) / 2][(map->width - 1) / 2 + 1]))
		{
			ft_putstr("Walls prevented placement of camera in middle of map.");
			ft_putstr(" Either remove the violating walls or specify a");
			ft_putstr(" starting position with a '2'\n");
			exit(1);
		}
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
