/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_on_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 10:48:15 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/03 10:51:46 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int					is_on_map(t_map *map, t_point *point)
{
	return (floor(point->x) >= 0 && floor(point->y) >= 0
			&& ceil(point->x) <= map->width && ceil(point->y) <= map->height);
}
