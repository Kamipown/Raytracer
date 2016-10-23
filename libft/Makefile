#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/02 14:03:15 by pdelobbe          #+#    #+#              #
#    Updated: 2016/10/13 21:19:26 by pdelobbe         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =		libft.a

FLG =		-Wall -Wextra -Werror

CFLAGS =	$(INC) $(FLG)

SRC =		ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_strdup.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strcat.c \
			ft_strncat.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_strnstr.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_strnew.c \
			ft_strdel.c \
			ft_strclr.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_strsub.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strsplit.c \
			ft_itoa.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putendl.c \
			ft_putnbr.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_compose.c \
			ft_compose_str.c \
			ft_isalnum_str.c \
			ft_isalpha_str.c \
			ft_isdigit_str.c \
			ft_strcut.c \
			ft_strjoin_f.c \
			ft_strjoin_ff.c \
			ft_strrev.c \
			ft_strtrunc.c \
			ft_strmax.c \
			get_next_line.c \
			ft_strlen_delim.c \
			ft_strdup_delim.c \
			ft_iswhitespace.c \
			ft_skip_line.c \
			ft_putnbr_endl.c \
			ft_isnumber.c \
			ft_atod.c \
			interval_i.c \
			interval_d.c

OBJ =		$(SRC:.c=.o)

INC =		-I./includes

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\t\033[35m[Creating]\033[37m library archive"
	@ar rc $(NAME) $(OBJ)
	@echo "\t\033[35m[Updating]\033[37m table of content"
	@ranlib $(NAME)

$(OBJ):
	@echo "\t\033[35m[Creating]\033[37m object files"
	@gcc -c $(FLG) $(SRC) $(INC)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
