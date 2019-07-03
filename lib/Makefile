##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## lib Makefile
##

SRC			=	src/printf/my_putchar.c					\
				src/printf/my_puterr.c					\
				src/printf/my_putstr.c					\
				src/printf/my_putnbr.c					\
				src/printf/my_putdouble.c				\
				src/printf/my_printf.c					\
				src/printf/print_arr.c					\
				src/str_handling/my_strlen.c			\
				src/str_handling/my_strcmp.c			\
				src/str_handling/my_strncmp.c			\
				src/str_handling/my_str_to_word_array.c	\
				src/str_handling/is_number.c			\
				src/str_handling/my_getnbr.c			\
				src/str_handling/my_str_cut.c			\
				src/str_handling/my_str_concat.c		\
				src/str_handling/my_strcpy.c			\
				src/str_handling/my_strdup.c			\
				src/str_handling/my_strsep.c			\
				src/str_handling/str_moove.c			\
				src/str_handling/my_arr_cpy.c			\
				src/str_handling/my_arrlen.c			\
				src/mem_handling/free_tab.c				\
				src/mem_handling/my_arrdup.c			\

OBJ			=	$(SRC:.c=.o)

NAME		=	libmy.a

CPPFLAGS	+=	-I./include

all: $(NAME)

$(NAME): $(OBJ)
	cp include/my.h ../include
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ) src/printf/*~ src/str_handling/*~ 	\
	include/*~ *# *~

fclean: clean
	rm -f $(NAME)

re:	fclean all
