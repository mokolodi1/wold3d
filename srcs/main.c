/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 18:33:38 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/21 22:17:02 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int					main(int argc, char **argv)
{
	t_map			map;

	if (argc != 2)
	{
		ft_putendl("Incorrect arguments: ./wolf3d map.wolf");
		ft_putendl("To help make compatible maps:");
		ft_putstr("https:");
		ft_putchar('/');
		ft_putchar('/');
		ft_putstr("docs.google.com/spreadsheets/d/1aRdje8c_uhFyBkuTSu");
		ft_putstr("m6NVpipAV-pKIJK65KAC3L9hg/edit?usp=sharing");
		ft_putchar('\n');
		exit(1);
	}
	ft_bzero(&map, sizeof(t_map));
	read_map(&map, argv[1]);
	setup_and_start_viewer(&map);
	return (0);
}
