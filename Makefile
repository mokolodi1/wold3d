#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 17:52:57 by tfleming          #+#    #+#              #
#    Updated: 2015/03/21 22:04:35 by tfleming         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =			wolf3d

CC =			gcc
CFLAGS =			-Wall -Werror -Wextra -g -O0

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
				setup_camera.o \
				expose_hook.o \
				key_hook.o \
				move_camera.o \
				rotate_camera.o \
				draw.o \
				send_ray.o \
				normalize_angle.o

all: $(NAME)

$(NAME): $(COMPILED)
	@make -C $(MLX)
	@make -C $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(LIB_FLAGS) $(COMPILED)
	@echo "made" $(NAME)

$(COMPILED): %.o: $(SRCS)/%.c
	@$(CC) -c $(CFLAGS) $(INC_FLAGS) $< -o $@

clean:
#	@make -C $(LIBFT) clean
	@-/bin/rm -f $(COMPILED)
	@echo "cleaned" $(NAME)

fclean: clean
#	@make -C $(LIBFT) fclean
	@-/bin/rm -f $(NAME)
	@echo "fcleaned" $(NAME)

re: fclean all
