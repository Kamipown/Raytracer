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

INCLUDES = -I./libft/includes/		\
		   -I./includes 			\
		   -I./sdl2/include/

FLG =	-Wall -Wextra -pedantic -O3 #-Werror

CFLAGS = $(INCLUDES) $(FLG)

MLX = -framework OpenGL -framework AppKit

LIBFT = -L./libft/ -lft

SDLFT = -framework Cocoa -framework SDL2

SRC = main.c				\
	  errors.c				\
	  init.c				\
	  quit.c				\
	  parser.c				\
	  file_reader.c			\
	  request_constructor.c	\
	  data_reader.c			\
	  data_transform.c		\
	  data_config.c			\
	  data_lights.c			\
	  data_planes.c			\
	  data_spheres.c		\
	  objects_data.c		\
	  loop.c				\
	  inputs.c				\
	  inputs_switch.c       \
	  move.c                \
	  hooks.c				\
	  draw.c				\
	  raytracer.c			\
	  ray.c					\
	  vec3_calc.c			\
	  vec3_calc_float.c		\
	  inter_spheres.c		\
	  inter_cylinders.c		\
	  inter_cones.c			\
	  inter_planes.c

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
