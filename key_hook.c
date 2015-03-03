/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 13:53:27 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/03 13:55:25 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int					key_hook(int keycode, t_environment *env)
{
	(void)env;
	ft_putstr("key: ");
	ft_putnbr(keycode);
	ft_putstr("\n");
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}
