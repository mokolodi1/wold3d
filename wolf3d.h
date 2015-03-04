/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 18:33:49 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/04 23:07:57 by tfleming         ###   ########.fr       */
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
# define HORIZONTAL_VIEWING_ANGLE	M_PI

# define MAP_PADDING				10

# define KEY_ESC            		65307
# define KEY_UP_ARROW				65362
# define KEY_LEFT_ARROW				65361
# define KEY_DOWN_ARROW				65364
# define KEY_RIGHT_ARROW			65363

# define DEGREE						0.0174532925
# define SCOPE						.5
# define VIEW_WIDTH					180

# define VELOCITY					.2
# define ANGULAR_VELOCITY			(DEGREE * 10)

# define BACKGROUND_COLOR			0x000000

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

typedef enum		e_direction
{
	EAST, NORTH, WEST, SOUTH
}					t_direction;

/*
** distance = -1 ==> no wall found
*/

typedef struct		s_ray
{
	double			distance;
	t_direction		color;
}					t_ray;

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
void				setup_and_start_viewer(t_map *map);
int					expose_hook(t_environment *env);
int					key_hook(int keycode, t_environment *env);

void				move(double x, double y, t_environment *env);

void            	draw(t_environment *env);
void				send_ray(t_ray *ray, t_map *map, t_point *location
										, double viewing_angle);
int					look_for_walls(t_map *map, t_camera *camera
										, t_line *current);
int					is_on_map(t_map *map, t_point *point);

void				set_wall_directions(t_camera *camera);//debug?
double				distance_between(t_point *first, t_point *second);
double				line_length(t_line *line);
double				degrees_to_radians(double degrees);
void				normalize_angle(double *angle);

int					mlx_rgb_to_color(int red, int green, int blue);

#endif
