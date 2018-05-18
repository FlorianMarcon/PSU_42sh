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
		$(WAY)/hm_env/generate_hm_env.c	\
		$(WAY)/get_next_instruction/parsing_command_line.c	\
		$(WAY)/get_next_instruction/get_next_instruction.c	\
		$(WAY)/get_next_instruction/parsing_change_variable.c	\
		$(WAY)/get_next_instruction/parsing_change_alias.c	\
		$(WAY)/get_next_instruction/separation_between_instruction_operator.c\
		$(WAY)/utilitaries/generate_shell.c	\
		$(WAY)/utilitaries/search_index_operator.c	\
		$(WAY)/utilitaries/is_executable.c	\
		$(WAY)/utilitaries/get_path.c		\
		$(WAY)/utilitaries/is_operator.c	\
		$(WAY)/utilitaries/my_addtab.c		\
		$(WAY)/utilitaries/my_tabcat.c		\
		$(WAY)/utilitaries/my_destroy_tab.c	\
		$(WAY)/utilitaries/display_prompt.c	\
		$(WAY)/builtin/env.c			\
		$(WAY)/builtin/set_env.c			\
		$(WAY)/builtin/current_directory.c	\
		$(WAY)/builtin/exit_program.c		\
		$(WAY)/builtin/set_local.c		\
		$(WAY)/builtin/unset_local.c		\
		$(WAY)/builtin/where.c		\
		$(WAY)/builtin/which.c		\
		$(WAY)/builtin/is_builtin.c		\
		$(WAY)/builtin/alias.c		\
		$(WAY)/run_cmd/run_cmd.c		\
		$(WAY)/run_cmd/run_pipe.c		\
		$(WAY)/run_cmd/run_and_or.c		\
		$(WAY)/run_cmd/run_right_chevron.c	\
		$(WAY)/run_cmd/run_left_chevron.c	\
		$(WAY)/run_cmd/run_semicolon.c		\
		$(WAY)/run_cmd/get_name_in_tree.c	\
		$(WAY)/run_cmd/run_background.c		\
		$(WAY)/execution/basic_exec.c		\
		$(WAY)/verification_cmd/verification_cmd.c	\
		$(WAY)/verification_cmd/verification_and.c		\
		$(WAY)/verification_cmd/verification_background.c		\
		$(WAY)/verification_cmd/verification_left_chevron.c		\
		$(WAY)/verification_cmd/verification_or.c		\
		$(WAY)/verification_cmd/verification_pipe.c		\
		$(WAY)/verification_cmd/verification_right_chevron.c		\
		$(WAY)/verification_cmd/verification_semicolon.c		\
		$(WAY)/get_next_line_custom/gnl_custom.c	\
		$(WAY)/get_next_line_custom/gnl_clear_nspace.c	\
		$(WAY)/get_next_line_custom/gnl_custom_set_terminal.c	\
		$(WAY)/get_next_line_custom/treatement/gnl_delete_char.c	\
		$(WAY)/get_next_line_custom/treatement/gnl_special.c	\
		$(WAY)/get_next_line_custom/treatement/gnl_arrow.c	\
		$(WAY)/variable/search_variable.c	\
		$(WAY)/variable/destroy_variable.c	\
		$(WAY)/variable/create_variable.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror -g3
CFLAGS	+=	-I./include

LDFLAGS	=	-lncurses

WAY_LIB	=	./lib/my

WAY_TST	=	./tests

LIB	=	-L$(WAY_LIB) -lmy

NAME	=	42sh

all:	$(NAME)

$(NAME):$(OBJ)
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
