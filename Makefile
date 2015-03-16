#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 17:52:57 by tfleming          #+#    #+#              #
#    Updated: 2015/03/16 14:55:40 by tfleming         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =			wolf3d

CC =			gcc
FLAGS =			-Wall -Werror -Wextra -g -O0

SRCS =			srcs
INCLUDES =		includes
LIBFT =                 libft
LIBFT_INCLUDES =	$(LIBFT)/includes
MLX =                   minilibx_macos

INC_FLAGS =             -I $(INCLUDES) -I $(LIBFT_INCLUDES) -I $(MLX)
LIB_FLAGS =             -L $(LIBFT) -lft -L $(MLX) -lmlx \
						-framework OpenGL -framework AppKit

COMPILED =		main.o \
				read_map.o \
				setup_and_start_viewer.o \
				expose_hook.o \
				key_hook.o \
				move_camera.o \
				rotate_camera.o \
				draw.o \
				send_ray.o \
				is_on_map.o \
				distance_between.o \
				line_length.o \
				normalize_angle.o \
				mlx_rgb_to_color.o

all: $(NAME)

$(NAME): $(COMPILED)
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) -o $(NAME) $(LIB_FLAGS) $(COMPILED)
	@echo "made" $(NAME)

$(COMPILED): %.o: $(SRCS)/%.c
	@$(CC) -c $(FLAGS) $(INC_FLAGS) $< -o $@

clean:
#	@make -C $(LIBFT) clean
	@-/bin/rm -f $(COMPILED)
	@echo "cleaned" $(NAME)

fclean: clean
#	@make -C $(LIBFT) fclean
	@-/bin/rm -f $(NAME)
	@echo "fcleaned" $(NAME)

re: fclean all
