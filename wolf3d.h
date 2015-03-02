/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 18:33:49 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/14 18:34:17 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

/*
** authorized functions:
** open
** read
** write
** close
** malloc
** free
** perror
** strerror
** exit
** math functions (-lm)
** minilibx functions (-lmlx)
*/

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h> // debug

# define DEFAULT_WINDOW_WIDTH		500
# define DEFAULT_WINDOW_HEIGHT		500
# define KEY_ESC            		65307

/* # define DIST(F, S) (sqrt(pow((S).x - (F).x, 2) + pow((S).y - (F).y, 2))) */
/* # define DISTANCE_BETWEEN(FIRST, SECOND) DIST(FIRST, SECOND) */
// undefine DIST

# define SMALLER(FIRST, SECOND) ((FIRST) < (SECOND) ? (FIRST) : (SECOND))
# define GREATER(FIRST, SECOND) ((FIRST) > (SECOND) ? (FIRST) : (SECOND))

typedef struct		s_point
{
	double			x;
	double			y;
}					t_point;

typedef struct		s_line
{
	t_point			first;
	t_point			second;
}					t_line;

typedef struct		s_map
{
	int				**data;
	int				height;
	int				width;
}					t_map;

typedef struct		s_camera
{
	t_point			location;
	double			direction;
	int				horizontal_wall_direction;
	int				vertical_wall_direction;
	double			horizontal_viewing_angle;
	double			vertical_viewing_angle;
}					t_camera;

typedef struct		s_environment
{
	void			*mlx;
	void			*window;
	int				window_height;
	int				window_width;
	t_map			*map;
	t_camera		camera;
}					t_environment;

void				read_map(t_map *map, char *filename);
void				setup_viewer(t_map *map);

int					expose_hook(t_environment *env);
int					key_hook(int keycode, t_environment *env);
void            	draw(t_environment *env);
int					get_wall_height(t_map *map, t_camera *camera
										, double viewing_angle);
int					look_for_walls(t_map *map, t_camera *camera, t_line *current);
void				set_wall_directions(t_camera *camera);
double				distance_between(t_point *first, t_point *second);
double				line_length(t_line *line);
double				degrees_to_radians(double degrees);

int					mlx_rgb_to_color(int red, int green, int blue);

#endif
