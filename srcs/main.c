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

/*
** I know how not cool the way pad_map is implemented, but it's only
** done once and super easy to understand.
*/

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

/* static void			set_new_map(t_map *map, int **new_data */
/* 								, int new_height, int new_width) */
/* { */
/* 	int				i; */

/* 	i = 0; */
/* 	while (i < map->height) */
/* 	{ */
/* 		free(map->data[i]); */
/* 		i++; */
/* 	} */
/* 	free(map->data); */
/* 	map->data = new_data; */
/* 	map->height = new_height; */
/* 	map->width = new_width; */
/* } */

/* static void			pad_map(t_map *map) */
/* { */
/* 	int				**new_data; */
/* 	int				new_height; */
/* 	int				new_width; */
/* 	int				i; */

/* 	new_height = map->height + MAP_PADDING * 2; */
/* 	new_width = map->width + MAP_PADDING * 2; */
/* 	new_data = malloc(new_height * sizeof(int*)); */
/* 	i = 0; */
/* 	while (i < new_height) */
/* 	{ */
/* 		new_data[i] = malloc(new_width * sizeof(int)); */
/* 		ft_bzero(new_data[i], new_width * sizeof(int)); */
/* 		if (i >= MAP_PADDING && i < MAP_PADDING + map->height) */
/* 			ft_memcpy(new_data[i] + MAP_PADDING */
/* 					  , map->data[i - MAP_PADDING], map->width * sizeof(int)); */
/* 		i++; */
/* 	} */
/* 	set_new_map(map, new_data, new_height, new_width); */
/* } */

int					main(int argc, char **argv)
{
	t_map			map;

	if (argc != 2)
		ft_putendl_exit("Incorrect arguments: ./wolf3d map.wolf", 1);
	ft_bzero(&map, sizeof(t_map));
	read_map(&map, argv[1]);
	print_map(&map);
	//pad_map(&map);
	printf("added padding...\n");
	print_map(&map);
	setup_and_start_viewer(&map);
	return (0);
}
