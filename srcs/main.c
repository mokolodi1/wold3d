/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 18:33:38 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/16 17:01:48 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void				print_map(t_map *map) // debug
{
	int				outer;
	int				inner;

	printf("map->height = %d\n", map->height);
	printf("map->width = %d\n", map->width);
	outer = 0;
	while (outer < map->height)
	{
		printf("[");
		inner = 0;
		while (inner < map->width - 1)
		{
			printf("%3d", map->data[outer][inner]);
			inner++;
		}
		printf("%3d]\n", map->data[outer][map->width - 1]);
		outer++;
	}
}

int					main(int argc, char **argv)
{
	t_map			map;

	if (argc != 2)
		ft_putendl_exit("Incorrect arguments: ./wolf3d map.wolf", 1);
	ft_bzero(&map, sizeof(t_map));
	read_map(&map, argv[1]);
	print_map(&map);
	setup_and_start_viewer(&map);
	return (0);
}
