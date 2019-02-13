##
## EPITECH PROJECT, 2017
## Makefile pour compresser lib
## File description:
## Makefile
##

CC	=	gcc

SRC	=	$(wildcard *.c)		\
		src_printf/print_int/print_int_speci.c	\
		src_printf/print_oct/print_oct_speci.c	\
		src_printf/print_hexa/print_hexa_speci.c	\
		src_printf/print_unint/print_unint_speci.c	\
		src_printf/my_printf.c	\
		src_printf/choice_function.c	\
		src_printf/functions_printfirst.c		\
		src_printf/functions_printsecond.c		\
		src_printf/functions_printthird.c		\
		src_printf/print_speci.c	\
		src_printf/find_speci.c		\
		convert_base/conv_base_to.c	\
		convert_base/convert_base.c	\
		convert_base/convert_baseten_to_n.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I../../include -W -Wall -Wextra -Werror

NAME	=	libmy.a

all:		$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
