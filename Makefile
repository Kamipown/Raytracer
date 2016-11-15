# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gromon <gromon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/08 02:35:08 by gromon            #+#    #+#              #
#    Updated: 2016/11/08 22:14:04 by dcognata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LOCALDIR = $(shell pwd)


LIBS = -L libft/ -lft -framework SDL2

NAME = rt

CC = gcc

PATH_SRC = ./sources/

INCLUDES =	-I./libft/includes/		\
			-I./includes 			\
			-I./sdl2/include/

INC = -I $(INCLUDES) -I libft/includes/ -I SDL2/include/
FLG = -Wall -Wextra -Werror -O3

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


SRC +=	load/load_textures.c			\
		load/free_textures.c

SRC+=	hooks/hooks.c

SRC+=	fullscreen/fullscreen.c

SRC+=	matrix/move_x_axis.c			\
		matrix/move_y_axis.c			\
		matrix/move_z_axis.c			\
		matrix/rotate_x_axis.c			\
		matrix/rotate_y_axis.c			\
		matrix/rotate_z_axis.c

SRC+=	draw/draw.c

SRC+=	raytracer/raytracer.c			\
		raytracer/raytracer_color.c		\

SRC+=	rays/ray.c

SRC+=	vec3/vec3_calc.c				\
		vec3/vec3_calc_double.c			\
		vec3/vec3_rotate.c

SRC+=	lighting/process_lighting.c			\
		lighting/point_light.c				\
		lighting/directional_light.c		\
		lighting/spot_light.c				\
		lighting/effect.c					\
		lighting/brightness.c

SRC+=	intersections/inter.c			\
		intersections/inter_spheres.c	\
		intersections/inter_cylinders.c	\
		intersections/inter_cones.c		\
		intersections/inter_planes.c

SRC+=	utilities/math_utilities.c			\
		utilities/color_utilities.c			\
		utilities/normal_utilities.c

SRC+=	textures/textures.c					\
		textures/perlin_noise.c				\
		textures/get_perlin_parameters.c	\
		textures/setup_perlin.c				\
		textures/bump_mapping.c

SRC+=	screenshoot/screenshoot.c

SRC+=	interface/mouse_interface.c

SRCS =	$(addprefix $(PATH_SRC), $(SRC))

SRCO =	$(SRCS:.c=.o)



all: libft $(NAME)

$(NAME): $(SRCO)
	@echo "\033[1;30mRT : Sources compiling...\033[0m"
	@$(CC) $(FLAGS) -o $@ $(SRCO) $(LIBS)
	@mkdir -p screenshoots
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
	@/bin/rm -rf screenshoots/
	@echo "\033[0;36mRT binary removed...\033[0m"

re: fclean all

norme:
	norminette sources/ includes/*.h libft/*.c libft/includes

.PHONY: clean fclean libft all $(NAME)
