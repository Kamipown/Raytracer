# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdelobbe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/18 19:44:49 by pdelobbe          #+#    #+#              #
#    Updated: 2016/09/10 13:21:56 by dcognata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		rtv1

CC =		gcc

FLG =		-Wall -Wextra -Werror -O3

INC =		-I ./includes \
			-I ./libft/includes/ \
			-I ./sdl2/include/

LIB =		-L./libft/ -lft \
			-L./minilibx_macos/ -lmlx \
			-framework OpenGL \
			-framework AppKit \
			-framework Cocoa \
			-framework SDL2

CFLAGS =	$(INC) $(FLG)

SRC_DIR =	sources/

SRC_FILES =	main.c \
			errors.c \
			init.c \
			parser.c \
			file_reader.c \
			request_constructor.c \
			data_reader.c \
			data_transform.c \
			data_config.c \
			data_lights.c \
			data_spheres.c \
			objects_data.c \
			hooks.c \
			draw.c \
			raytracer.c \
			ray.c

SRC =		$(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ =		$(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[33m[Step 2/4]\033[37m Libft"
	@make -C libft/
	@echo "\033[33m[Step 3/4]\033[37m Libmlx"
	@make -C minilibx_macos/
	@echo "\033[33m[Step 4/4]\033[37m Raytracer"
	@echo "\t\033[35m[Creating]\033[37m executable"
	@$(CC) -o $(NAME) $(OBJ) $(LIB)
	@echo "\033[32m[ Done ! ]"

$(OBJ):
	@echo "\033[33m[Step 1/4]\033[37m Raytracer"
	@echo "\t\033[35m[Creating]\033[37m object files"
	@$(CC) -c -O3 $(FLG) $(INC) $(SRC)


clean:
	@echo "\033[33m[clean]"
	@echo "\t\033[31m[Deleting]\033[37m object files"
	@echo "\t\033[31m[Deleting]\033[37m temporary files"
	@rm -f $(OBJ)
	@rm -Rf **/*~
	@make clean -C libft/
	@make clean -C minilibx_macos/

fclean: clean
	@echo "\033[33m[fclean]"
	@echo "\t\033[31m[Deleting]\033[37m libs"
	@echo "\t\033[31m[Deleting]\033[37m executable"
	@rm -f $(NAME)
	@make fclean -C libft/
	@make fclean -C minilibx_macos/

re: fclean all

test: re
	./rtv1 scenes/scene_00.rt

retest:
	./rtv1 scenes/scene_00.rt

norm:
	norminette sources/*.c includes/*.h libft/*.c libft/includes/*.h

aaa:
	gcc $(TTT)
