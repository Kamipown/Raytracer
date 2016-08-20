# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdelobbe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/18 19:44:49 by pdelobbe          #+#    #+#              #
#    Updated: 2016/04/18 19:44:57 by pdelobbe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		rtv1

cc =		gcc

FLG =		-Wall -Wextra -Werror

INC =		-I ./includes -I ./libft/includes/

LIB =		-L./libft/ -lft -L./minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

CFLAGS =	$(INC) $(FLG)

SRC =		main.c \
			errors.c \
			init.c \
			parser.c \
			file_reader.c \
			data_reader.c \
			config_data.c \
			objects_data.c \
			hooks.c \
			draw.c

OBJ =		$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	make -C minilibx_macos/
	$(CC) -O3 $(FLG) $(INC) -c $(SRC)
	$(CC) -g -o $(NAME) $(OBJ) $(LIB)

clean:
	rm -f $(OBJ)
	rm -Rf **/*~
	make clean -C libft/
	make clean -C minilibx_macos/

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all

test: re
	./rtv1 scenes/scene_00.rt

retest:
	./rtv1 scenes/scene_00.rt

norm:
	norminette *.c includes/*.h libft/*.c libft/includes/*.h
