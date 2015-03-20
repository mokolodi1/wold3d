/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 13:53:40 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/20 15:56:32 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void			validate_int(char *string, int number)
{
	if (!ft_is_valid_int(string)
		|| !(number == 0 || number == 1 || number == 2))
	{
		ft_printf("Invalid token in map file: %s\n", string);
		exit(1);
	}
}

static int			do_line(int fd, int **ints, int *width)
{
	char	*line;
	int		read_ret;
	char	**split;
	int		i;

	read_ret = get_next_line(fd, &line);
	if (read_ret == -1)
		ft_putendl_exit("Error reading file", 1);
	split = ft_strsplit(line, ' ');
	*width = ft_arrlen(split);
	*ints = malloc(*width * sizeof(int));
	i = 0;
	while (i < *width)
	{
		(*ints)[i] = ft_atoi(split[i]);
		validate_int(split[i], (*ints)[i]);
		i++;
	}
	if (split && *split)
		ft_strsplit_free(split);
	free(line);
	return (read_ret);
}

static void			process_rest(int fd, t_list **int_list
								, int expect_width
								, int *height)
{
	int			*curr_ints;
	int			width;

	while (do_line(fd, &curr_ints, &width))
	{
		if (width != expect_width)
			ft_putendl_exit("One of the lines is not like the others!", 1);
		ft_list_push_back(int_list, curr_ints);
		(*height)++;
	}
}

static void			list_to_map(t_list **ints_list, t_map *map)
{
	int				i;
	t_list			*current_ints;

	map->data = malloc(map->height * sizeof(int*));
	current_ints = *ints_list;
	i = 0;
	while (current_ints)
	{
		map->data[i] = current_ints->data;
		i++;
		current_ints = current_ints->next;
	}
	ft_list_clear(ints_list);
}

void				read_map(t_map *map, char *filename)
{
	int			fd;
	int			*curr_ints;
	t_list		*ints_list;

	fd = open(filename, O_RDONLY);
	do_line(fd, &curr_ints, &map->width);
	if (map->width <= 0)
		ft_putendl_exit("Must have at least one line of data", 1);
	ints_list = NULL;
	ft_list_push_back(&ints_list, curr_ints);
	map->height = 1;
	process_rest(fd, &ints_list, map->width, &map->height);
	if (map->width <= 1 || map->height <= 1)
		ft_putendl_exit("Map width and hight must be greater than one", 1);
	list_to_map(&ints_list, map);
	close(fd);
}
