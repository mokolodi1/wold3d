/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   degrees_to_radians.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 13:53:12 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/03 15:17:06 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

double				degrees_to_radians(double degrees)
{
	return (degrees * M_PI / 180);
}
