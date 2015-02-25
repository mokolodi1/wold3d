#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 17:52:57 by tfleming          #+#    #+#              #
#    Updated: 2015/01/24 15:36:21 by tfleming         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =			wolf3d

CC =			gcc
FLAGS =			-Wall -Werror -Wextra -g

LIBFT =                 "libft/"
X11 =                   "/usr/X11/lib"
MLX =                   "minilibx/"

INC_FLAGS =             -I $(LIBFT) -I $(MLX)
LIB_FLAGS =             -L $(LIBFT) -L $(X11) -L $(MLX) -lft -lmlx -lXext -lX11

COMPILED =		main.o \
			read_map.o \
			setup_viewer.o \
			expose_hook.o \
			key_hook.o \
			draw.o \
			get_wall_height.o \
			mlx_rgb_to_color.o

all: $(NAME)

$(NAME): $(COMPILED)
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) -o $(NAME) $(LIB_FLAGS) $(COMPILED)
	@echo "made" $(NAME)

$(COMPILED): %.o: %.c
	@$(CC) -c $(FLAGS) $(INC_FLAGS) $< -o $@

clean:
	@make -C $(LIBFT) clean
	@-/bin/rm -f $(COMPILED)
	@echo "cleaned" $(NAME)

fclean: clean
	@make -C $(LIBFT) fclean
	@-/bin/rm -f $(NAME)
	@echo "fcleaned" $(NAME)

re: fclean all
