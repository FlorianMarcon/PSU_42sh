##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## corewar
##

CC	=	gcc

WAY	=	./src

SRC	=	$(WAY)/main.c	\
		$(WAY)/get_next_line_custom/gnl_custom.c	\
		$(WAY)/get_next_line_custom/treatement/gnl_delete_char.c	\
		$(WAY)/get_next_line_custom/treatement/gnl_special.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror -g3
CFLAGS	+=	-I../include

LDFLAGS	=	-lncurses -L../lib/my -lmy

WAY_TST	=	./tests

NAME	=	42sh

all:	$(OBJ)
	make -C../lib/my
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	clean all

tests_run:
	make -C./$(WAY_TST)
