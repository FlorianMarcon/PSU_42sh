##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## corewar
##

CC	=	gcc

WAY	=	./src

SRC	=	$(WAY)/main.c	\
		$(WAY)/shell.c	\
		$(WAY)/hash_map/hash_get_key.c		\
		$(WAY)/hash_map/generate_hash_map.c	\
		$(WAY)/hash_map/hm_generate_object.c	\
		$(WAY)/hash_map/hm_get_last_object.c	\
		$(WAY)/hash_map/hm_add_object.c		\
		$(WAY)/hash_map/hm_get_object.c		\
		$(WAY)/hash_map/hm_destroy.c		\
		$(WAY)/hm_binary/put_binary_in_hm.c	\
		$(WAY)/hm_binary/analyse_file.c		\
		$(WAY)/hm_binary/hm_binary_list_all_file.c	\
		$(WAY)/hm_binary/generate_hm_binary.c	\
		$(WAY)/hm_env/generate_name_and_arg_var_env.c	\
		$(WAY)/hm_env/generate_list_env.c	\
		$(WAY)/tree/tree_create_node.c		\
		$(WAY)/tree/tree_link_node.c		\
		$(WAY)/tree/destroy_tree.c		\
		$(WAY)/utilitaries/is_executable.c	\
		$(WAY)/hm_env/generate_hm_env.c	\
		$(WAY)/utilitaries/search_index_operator.c	\
		$(WAY)/utilitaries/parsing_command_line.c	\
		$(WAY)/utilitaries/get_next_instruction.c	\
		$(WAY)/utilitaries/generate_shell.c	\
		$(WAY)/utilitaries/get_path.c		\
		$(WAY)/utilitaries/is_operator.c	\
		$(WAY)/utilitaries/my_addtab.c		\
		$(WAY)/utilitaries/display_prompt.c	\
		$(WAY)/utilitaries/separation_between_instruction_operator.c\
		$(WAY)/builtin/env.c			\
		$(WAY)/builtin/set_env.c			\
		$(WAY)/builtin/current_directory.c	\
		$(WAY)/builtin/exit_program.c		\
		$(WAY)/run_cmd/run_cmd.c		\
		$(WAY)/run_cmd/run_pipe.c		\
		$(WAY)/run_cmd/run_right_chevron.c	\
		$(WAY)/run_cmd/run_left_chevron.c	\
		$(WAY)/run_cmd/run_semicolon.c		\
		$(WAY)/run_cmd/get_name_in_tree.c	\
		$(WAY)/execution/basic_exec.c		\
		$(WAY)/verification_cmd/verification_cmd.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror -g3
CFLAGS	+=	-I./include

LDFLAGS	=

WAY_LIB	=	./lib/my

WAY_TST	=	./tests

LIB	=	-L$(WAY_LIB) -lmy

NAME	=	42sh

all:	$(OBJ)
	make -C./$(WAY_LIB)
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(LDFLAGS)

clean:
	make clean -C./$(WAY_TST)
	make clean -C./$(WAY_LIB)
	$(RM) $(OBJ)

fclean:	clean
	make fclean -C./$(WAY_TST)
	make fclean -C./$(WAY_LIB)
	$(RM) $(NAME)

re:	clean all

tests_run:
	make -C./$(WAY_TST)
