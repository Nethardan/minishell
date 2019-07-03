##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## main Makefile
##

SRC		=	src/main.c			\
			src/errors.c		\
			src/my_exit.c		\
			src/execution.c		\
			src/get_env_value.c	\
			src/exec_setenv.c	\
			src/exec_unsetenv.c	\
			src/find_path.c		\
			src/exec_cd.c		\
			src/print_prompt.c	\
			src/print_signal.c	\
			src/is_filetype.c	\

OBJ		=	$(SRC:.c=.o)

NAME		=	mysh

CPPFLAGS	+=	-I./include

FLAGS		=	-L./lib -lmy

all: $(NAME)

$(NAME): $(OBJ)
	make -C lib/
	gcc -o $(NAME) $(OBJ) $(FLAGS)
	cp $(NAME) tester

debug:	CFLAGS += -g
debug: 	fclean $(NAME)
	valgrind ./$(NAME)

libmy:
	make -C lib/

clean:
	rm -f $(OBJ) src/*~ src/*# include/*~ include/*# *~ *#
	make -C lib/ clean

fclean: clean
	rm -f $(NAME)
	make -C lib/ fclean

re: fclean all
