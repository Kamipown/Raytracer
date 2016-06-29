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

NAME =	rtv1

cc =	cc

FLG =	-Wall -Wextra -Werror

INC =	-I ./includes -I ./libft/includes/

CFLAGS=	$(INC) $(FLG)

SRC =	main.c \
		init.c \
		get_next_line.c \
		parser.c \
		hooks.c \
		draw.c \
		errors.c

OBJ =	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	make -C minilibx_macos
	$(CC) -O3 $(FLG) $(INC) -c $(SRC)
	$(CC) -g -o $(NAME) $(OBJ) -L./libft/ -lft -L./minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

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
