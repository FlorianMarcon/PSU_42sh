##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## corewar
##

CC	=	gcc

WAY	=	../src

SRC	=	$(WAY)/shell.c	\
		$(WAY)/hash_map/hash_get_key.c		\
		$(WAY)/hash_map/generate_hash_map.c	\
		$(WAY)/hash_map/hm_generate_object.c	\
		$(WAY)/hash_map/hm_get_last_object.c	\
		$(WAY)/hash_map/hm_add_object.c		\
		$(WAY)/hash_map/hm_get_object.c		\
		$(WAY)/hash_map/hm_destroy.c		\
		$(WAY)/env/create_linked_env.c		\
		$(WAY)/env/env.c			\
		$(WAY)/env/setenv.c			\
		$(WAY)/env/unsetenv.c			\
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
		$(WAY)/get_next_instruction/parsing_command_line.c	\
		$(WAY)/get_next_instruction/get_next_instruction.c	\
		$(WAY)/get_next_instruction/replace_variable.c	\
		$(WAY)/get_next_instruction/separation_between_instruction_operator.c\
		$(WAY)/utilitaries/generate_shell.c	\
		$(WAY)/utilitaries/get_path.c		\
		$(WAY)/utilitaries/is_operator.c	\
		$(WAY)/utilitaries/my_addtab.c		\
		$(WAY)/utilitaries/display_prompt.c	\
		$(WAY)/builtin/current_directory.c	\
		$(WAY)/builtin/exit_program.c		\
		$(WAY)/builtin/set_local.c		\
		$(WAY)/builtin/unset_local.c		\
		$(WAY)/builtin/where.c		\
		$(WAY)/builtin/which.c		\
		$(WAY)/builtin/is_builtin.c		\
		$(WAY)/utilitaries/get_old_pwd.c	\
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
                $(WAY)/get_next_line_custom/auto_complétion/auto_completion_launch.c    \
#		$(WAY)/builtin/env.c			\
#		$(WAY)/builtin/set_env.c			\

SRC_UT	=	hash_map/tests_utils.c			\
		hash_map/tests_utils_second.c			\
		utilitaries/is_executable/tests_utils.c	\
		utilitaries/get_path/tests_utils.c	\
		utilitaries/search_index_operator/tests_utils.c	\
		utilitaries/my_tabdup/tests_utils.c	\
		utilitaries/my_addtab/tests_utils.c	\
		get_next_instruction/parsing_command_line/tests_utils.c	\
		get_next_instruction/parsing_command_line/tests_utils_second.c	\
		get_next_instruction/get_next_instruction/tests_utils.c	\
		get_next_instruction/replace_variable/tests_utils.c	\
		get_next_instruction/separation_between_instruction_operator/tests_utils.c\
		hm_binary/tests_utils.c			\
		hm_binary/tests_utils_second.c		\
		tree/tree_create_node/tests_utils.c	\
		tree/tree_link_node/tests_utils.c	\
		auto_complétion/tests_utils.c		\
		verification/verification_and/tests_utils.c	\
		verification/verification_background/tests_utils.c	\
		verification/verification_left_chevron/tests_utils.c	\
		verification/verification_right_chevron/tests_utils.c	\
		verification/verification_pipe/tests_utils.c	\
		verification/verification_or/tests_utils.c	\
		verification/verification_semicolon/tests_utils.c	\
		variable/search_variable/tests_utils.c	\
		variable/create_variable/tests_utils.c	\
		builtin/set_local/tests_utils.c	\
		builtin/unset_local/tests_utils.c	\
		verification/verification_cmd/tests_utils.c		\
#		builtin/env/tests_utils.c		\
#		hm_env/tests_utils.c			\

OBJ	=	$(SRC:.c=.o)

OBJ_UT	=	$(SRC_UT:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror -g3 --coverage -I../include

LDFLAGS	=	-lcriterion -lgcov

WAY_LIB	=	../lib/my

LIB	=	-L$(WAY_LIB) -lmy

NAME	=	units

all:	$(NAME)

$(NAME):$(OBJ) $(OBJ_UT)
	make -C./$(WAY_LIB)
	$(CC) -o $(NAME) $(OBJ) $(OBJ_UT) $(LIB) $(LDFLAGS)
	./$(NAME)
clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_UT)
	$(RM) $(OBJ:.o=.gcda)
	$(RM) $(OBJ:.o=.gcno)
	$(RM) $(OBJ_UT:.o=.gcda)
	$(RM) $(OBJ_UT:.o=.gcno)

fclean:	clean
	$(RM) $(NAME)

re:	clean all
