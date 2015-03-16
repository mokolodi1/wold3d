/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 18:33:49 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/16 18:50:31 by tfleming         ###   ########.fr       */
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
# include "get_next_line.h"
# include "ft_printf.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define RADIANS_TO_DEGREES(RADIANS) (RADIANS * 180 / M_PI)
# define DEGREES_TO_RADIANS(RADIANS) (RADIANS * M_PI / 180)

# define WINDOW_WIDTH			10
# define WINDOW_HEIGHT			10

# define MAP_PADDING			5

# define KEY_ESC            	53
# define KEY_UP_ARROW			126
# define KEY_LEFT_ARROW			123
# define KEY_DOWN_ARROW			125
# define KEY_RIGHT_ARROW		124

# define KEY_Q					12
# define KEY_W					13
# define KEY_E					14
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2

# define KEY_COMMA				43
# define KEY_PERIOD				47

/*
** scope = multiplier for vertical part of triangle in atan
*/

# define DEGREE					DEGREES_TO_RADIANS(1)
# define SCOPE					1
# define VIEW_WIDTH				DEGREES_TO_RADIANS(180)
# define VIEW_HEIGHT			(VIEW_WIDTH * (WINDOW_HEIGHT / WINDOW_WIDTH))

# define VELOCITY				.2
# define ANGULAR_VELOCITY		(DEGREE * 10)

# define BACKGROUND_COLOR		0x000000

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
	t_direction		direction;
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

void				move_camera(double x, double y, t_environment *env);
void				rotate_camera(t_environment *env, double delta_angle);

void            	draw(t_environment *env);
void				send_ray(t_ray *ray, t_map *map, t_point *location
										, double viewing_angle);
int					is_on_map(t_map *map, t_point *point);

double				distance_between(t_point *first, t_point *second);
double				line_length(t_line *line);
void				normalize_angle(double *angle);

int					mlx_rgb_to_color(int red, int green, int blue);

#endif
