# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/11 13:43:04 by dcognata          #+#    #+#              #
#    Updated: 2016/10/05 16:40:33 by dcognata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rt

CC = gcc

PATH_SRC = ./sources/

INCLUDES =	-I./libft/includes/		\
			-I./includes 			\
			-I./sdl2/include/

FLG =	-Wall -Wextra -pedantic -O3 #-Werror

CFLAGS = $(INCLUDES) $(FLG)

MLX = -framework OpenGL -framework AppKit

LIBFT = -L./libft/ -lft

SDLFT =	-framework Cocoa -framework SDL2

# SOURCES
SRC =	main.c

SRC +=	errors/errors.c

SRC +=	init/init.c

SRC +=	quit/quit.c

SRC +=	parser/parser.c					\
		parser/file_reader.c			\
		parser/request_constructor.c	\
		parser/data_reader.c			\
		parser/data_transform.c			\
		parser/data_config.c			\
		parser/data_lights.c			\
		parser/data_planes.c			\
		parser/data_spheres.c			\
		parser/objects_data.c

SRC +=	loop/loop.c

SRC +=	inputs/inputs.c					\
		inputs/inputs_keys.c			\
		inputs/inputs_mouse.c

SRC+=	hooks/hooks.c

SRC+=	fullscreen/fullscreen.c

SRC+=	matrix/move_x_axis.c			\
		matrix/move_y_axis.c			\
		matrix/move_z_axis.c

SRC+=	draw/draw.c

SRC+=	raytracer/raytracer.c

SRC+=	rays/ray.c

SRC+=	vec3/vec3_calc.c				\
		vec3/vec3_calc_double.c

SRC+=	intersections/inter_spheres.c	\
		intersections/inter_cylinders.c	\
		intersections/inter_cones.c		\
		intersections/inter_planes.c

SRCS = $(addprefix $(PATH_SRC), $(SRC))

SRCO = $(SRCS:.c=.o)

all: libft $(NAME)

$(NAME): $(SRCO)
	@echo "\033[1;30mRT : Sources compiling...\033[0m"
	@$(CC) $(FLAGS) -o $@ $(SRCO) $(LIBFT) $(SDLFT) $(MLX)
	@echo "\033[0;36mRT compile with success !\033[0m"

libft:
	make -C libft

clean:
	@make -C libft/ clean
	@/bin/rm -f $(SRCO)
	@echo "\033[0;36mObjects removed...\033[0m"

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)
	@echo "\033[0;36mRT binary removed...\033[0m"

re: fclean all

.PHONY: clean fclean libft all $(NAME)
