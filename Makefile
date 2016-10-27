# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: splace <splace@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/11 13:43:04 by dcognata          #+#    #+#              #
#    Updated: 2016/10/23 18:13:44 by splace           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LOCALDIR = $(shell pwd)


LIBS = -L libft/ -lft -L SDL2/lib/ -lSDL2


NAME = rt

CC = gcc

PATH_SRC = ./sources/

INCLUDES =	-I./libft/includes/		\
			-I./includes 			\
			-I./sdl2/include/

INC = -I $(INCLUDES) -I libft/includes/ -I SDL2/include/

FLG =  -g -Wall -Wextra -pedantic #-Werror 

CFLAGS = $(INCLUDES) $(FLG)

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
		parser/data_cones.c				\
		parser/data_cylinders.c			\
		parser/data_get.c

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

SRC+=	lighting/process_lighting.c

SRC+=	intersections/inter.c	\
		intersections/inter_spheres.c	\
		intersections/inter_cylinders.c	\
		intersections/inter_cones.c		\
		intersections/inter_planes.c

SRC+=	debug/debug.c

SRC+=	utilities/solve.c

SRCS =	$(addprefix $(PATH_SRC), $(SRC))

SRCO =	$(SRCS:.c=.o)



all: libft $(NAME)

$(NAME): $(SRCO)
	@echo "\033[1;30mRT : Sources compiling...\033[0m"
	@$(CC) $(FLAGS) -o $@ $(SRCO) $(LIBS)
	@echo "\033[0;36mRT compile with success !\033[0m"

libft:
	make -C libft

install:
	@mkdir -p SDL2
	@echo "SDL2     : "
	cd $(LOCALDIR)/lib && tar -zxvf SDL2-2.0.4.tar.gz
	cd $(LOCALDIR)/lib/SDL2-2.0.4 && ./configure --prefix=$(LOCALDIR)/SDL2 && make install
	rm -rf $(LOCALDIR)/lib/SDL2-2.0.4

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
