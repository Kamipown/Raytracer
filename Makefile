# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/11 13:43:04 by dcognata          #+#    #+#              #
#    Updated: 2016/03/02 15:17:41 by dcognata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rt

CC = gcc

PATH_SRC = ./sources/

INCLUDES = -I./libft/includes/		\
		   -I./minilibx_macos/		\
		   -I./includes 			\
		   -I./sdl2/include/

FLG =	-Wall -Wextra -pedantic -O3 #-Werror

CFLAGS = $(INCLUDES) $(FLG)

MLX = -L./minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

LIBFT = -L./libft/ -lft

SDLFT = -framework Cocoa -framework SDL2

SRC = main.c				\
	  errors.c				\
	  init.c				\
	  parser.c				\
	  file_reader.c			\
	  request_constructor.c	\
	  data_reader.c			\
	  data_transform.c		\
	  data_config.c			\
	  data_lights.c			\
	  data_spheres.c		\
	  objects_data.c		\
	  hooks.c				\
	  draw.c				\
	  raytracer.c			\
	  ray.c

SRCS = $(addprefix $(PATH_SRC), $(SRC))

SRCO = $(SRCS:.c=.o)

all: libft minilibx $(NAME)

$(NAME): $(SRCO)
	@echo "\033[1;30mRT : Sources compiling...\033[0m"
	@$(CC) $(FLAGS) -o $@ $(SRCO) $(LIBFT) $(SDLFT) $(MLX)
	@echo "\033[0;36mRT compile with success !\033[0m"

libft:
	make -C libft

minilibx:
	@make -C minilibx_macos/

clean:
	@make -C libft/ clean
	@/bin/rm -f $(SRCO)
	@echo "\033[0;36mObjects removed...\033[0m"

fclean: clean
	@make -C libft/ fclean
	@make -C minilibx_macos/ clean
	@/bin/rm -f $(NAME)
	@echo "\033[0;36mRT binary removed...\033[0m"

re: fclean all

.PHONY: clean fclean libft all $(NAME)
