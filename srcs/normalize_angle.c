/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_angle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 15:41:13 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/17 14:50:02 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** makes angles between 0 and M_PI
** example: 4 ==> 4 - M_PI
** note: that's as clear as I can be, and I'm not going to be using
** this for values outside [-2 * M_PI, 4 * M_PI] (that's why I'm using
** a while, not some math formula)
*/

void				normalize_angle(double *angle)
{
	while (*angle < 0)
		*angle += 2 * M_PI;
	while (*angle > 2 * M_PI)
		*angle -= 2 * M_PI;
}
