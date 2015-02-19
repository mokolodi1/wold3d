/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 18:33:38 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/14 18:34:47 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			print_map(t_map *map) // debug
{
	printf("map->width = %d\n", map->width);
	printf("map->height = %d\n", map->height);
	for (int outer = 0; outer < map->height; outer++)
	{
		printf("[");
		for (int inner = 0; inner < map->width - 1; inner++)
			printf("%3d", map->data[outer][inner]);
		printf("%3d]\n", map->data[outer][map->width - 1]);
	}
}

int				main(int argc, char **argv)
{
	t_map		map;

	if (argc != 2)
		ft_putendl_exit("Incorrect arguments: ./wolf3d map.wolf", 1);
	ft_bzero(&map, sizeof(t_map));
	read_map(&map, argv[1]);
	print_map(&map);
	setup_viewer(&map);
	return (0);
}
