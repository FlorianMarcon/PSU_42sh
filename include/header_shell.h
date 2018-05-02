/*
** EPITECH PROJECT, 2017
** header_shell
** File description:
** header_shell
*/

#ifndef SHELL_
#define SHELL_

#include <stdbool.h>
#include "hash_map.h"
#include "tree.h"

typedef struct shell_s {
	// var env
	hash_map_t *env;
	env_t *env;
	char **arr_env;
	char pwd[100];
	char *old_pwd;

	//binary
	hash_map_t *binary;

	//
	bool exit;
	int value_exit;

}shell_t;

int	minishell(shell_t *shell);

// utilitaries

int	is_executable(char *path);

int	search_index_operator(char **cmd);

tree_t	*parsing_command_line(char **cmd);

char	**create_tab_op_for_command_line(char *str);

tree_t	*get_next_instruction(shell_t *shell, int fd);

shell_t	*generate_shell(char **envp);

char	*get_path(hash_map_t *map_binary, char *cmd);

int	is_operator(char *str);

char	**my_addtab(char **tab, char *str);

char	*get_name_in_tree(tree_t *tree);

void	display_prompt(shell_t *shell);

char	*new_str(char *str, int i, char *op);

char	*operator_is_present(char *str);

char	*separation_between_instruction_operator(char *str);

int	verification_cmd(tree_t *node);

// builtin

typedef struct built_s {
	char *label;
	int (*ptr)(shell_t *, char **);
}built_t;

int	env(shell_t *shell, char **cmd);

int	exit_program(shell_t *shell, char **cmd);

int	current_directory(shell_t *shell, char **cmd);

int	set_env(shell_t *shell, char **cmd);

static const built_t builtin [5] = {
	{"env", env},
	{"exit", exit_program},
	{"cd", current_directory},
	{"setenv", set_env},
	{NULL, NULL}
};
// run cmd

typedef struct optab_s {
	char *label;
	int (*ptr)(shell_t *shell, tree_t *tree);
}optab_t;

int	run_pipe(shell_t *shell, tree_t *tree);

int	run_right_chevron(shell_t *shell, tree_t *tree);

int	run_double_right_chevron(shell_t *shell, tree_t *tree);

int	run_left_chevron(shell_t *shell, tree_t *tree);

int	run_semicolon(shell_t *shell, tree_t *tree);

static const optab_t run_op[8] = {
	{";", run_semicolon},
	{"|", run_pipe},
	{"&", NULL},
	{"<", run_left_chevron},
	{"<<", NULL},
	{">", run_right_chevron},
	{">>", run_double_right_chevron},
	{NULL, NULL}
};

int	run_cmd(shell_t *shell, tree_t *tree);

// execution

int	basic_exec(shell_t *shell, char **cmd);

#endif
