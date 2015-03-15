/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_between.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 13:50:49 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/03 13:50:52 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

double				distance_between(t_point *first, t_point *second)
{
	return (sqrt(pow(second->x - first->x, 2) + pow(second->y - first->y, 2)));
}
