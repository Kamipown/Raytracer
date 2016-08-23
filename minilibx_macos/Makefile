#
#

NOM =		libmlx.a

SRC =		mlx_shaders.c \
			mlx_new_window.m \
			mlx_init_loop.m \
			mlx_new_image.m \
			mlx_xpm.c \
			mlx_int_str_to_wordtab.c

OBJ1 =		$(SRC:.c=.o)
OBJ =		$(OBJ1:.m=.o)

CFLAGS +=	-O2

all: $(NOM)

$(NOM):	$(OBJ)
	@echo "\t\033[35m[Creating]\033[37m library archive"
	@ar rc $(NOM) $(OBJ)
	@echo "\t\033[35m[Updating]\033[37m table of content"
	@ranlib $(NOM)

$(OBJ):
	@echo "\t\033[35m[Creating]\033[37m object files"
	@gcc -c $(SRC)

clean:
	@rm -f $(OBJ) *~
	@rm -f mlx_app

fclean:
	@rm -f $(NOM)

re: clean all
