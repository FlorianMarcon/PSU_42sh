/*
** EPITECH PROJECT, 2017
** header_shell
** File description:
** header_shell
*/

#ifndef SHELL_
#define SHELL_

#include <stdbool.h>
#include <termios.h>
#include <unistd.h>
#include "hash_map.h"
#include "tree.h"
#include "variable.h"

typedef struct shell_s {
	// var env
	linked_list_t *list_env;
	char **arr_env;
	char pwd[100];
	char *old_pwd;

	// local variable
	linked_list_t *list_local;

	//binary
	hash_map_t *binary;
	linked_list_t *process_back;

	// exit
	bool exit;
	int value_exit;

	//termios
	struct termios term;
	struct termios old_term;

	//allias
	linked_list_t *list_alias;

	//history
	char *history[30];
	unsigned int size_history;

}shell_t;

int	minishell(shell_t *shell);

// get_next_instruction

tree_t	*get_next_instruction(shell_t *shell, int fd);

tree_t	*parsing_command_line(char **cmd);

char	*separation_between_instruction_operator(char *str);

char	*parsing_change_variable(char *str, shell_t *shell);

char	**parsing_change_alias(linked_list_t *list, char **cmd);

char	*replace_variable(char *str, int i, shell_t *shell);

// utilitaries

int	is_executable(char *path);

int	search_index_operator(char **cmd);

char	**create_tab_op_for_command_line(char *str);

unsigned int	generate_shell(char **envp, shell_t *shell);

char	*get_path(hash_map_t *map_binary, char *cmd);

int	is_operator(char *str);

char	**my_addtab(char **tab, char *str);

char	**my_tabcat(char **fir, char **sec);

void	my_destroy_tab(char **tab);

char	*get_name_in_tree(tree_t *tree);

void	display_prompt(shell_t *shell);

char	*new_str(char *str, int i, char *op);

char	*operator_is_present(char *str);

int	verification_cmd(tree_t *node);

int	*create_pipe(void);

char	*get_old_pwd(linked_list_t *env);

linked_list_t	*init_env(char **envp);

void	sort_list(linked_list_t *list);

int	my_char_ispresent(char *str, char label);

void	sync_pwd(shell_t *shell);

void	put_instruction_in_history(shell_t *shell, char *str);

// builtin

typedef struct built_s {
	char *label;
	int (*ptr)(shell_t *, char **);
}built_t;

bool	is_builtin(char *cmd);

int	exit_program(shell_t *shell, char **cmd);

int	current_directory(shell_t *shell, char **cmd);

linked_list_t	*init_env(char **envp);

int	set_env(shell_t *shell, char **cmd);

int	unset_env(shell_t *shell, char **cmd);

int	env(shell_t *shell, char **cmd);

int	where(shell_t *shell, char **cmd);

int	which(shell_t *shell, char **cmd);

int	set_local(shell_t *shell, char **cmd);

void	create_variable_local(shell_t *shell, char **cmd, unsigned int *i);

int	unset_local(shell_t *shell, char **cmd);

int	alias(shell_t *shell, char **cmd);

int	fg_builtin(shell_t *shell, char **cmd);

int	repeat(shell_t *shell, char **cmd);

static const built_t builtin [13] = {
	{"env", env},
	{"exit", exit_program},
	{"cd", current_directory},
	{"setenv", set_env},
	{"unsetenv", unset_env},
	{"where", where},
	{"which", which},
	{"set", set_local},
	{"unset", unset_local},
	{"alias", alias},
	{"fg", fg_builtin},
	{"repeat", repeat},
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

int	run_double_left_chevron(shell_t *shell, tree_t *tree);

int	run_semicolon(shell_t *shell, tree_t *tree);

int	run_or(shell_t *shell, tree_t *tree);

int	run_and(shell_t *shell, tree_t *tree);

int	run_background(shell_t *shell, tree_t *node);

static const optab_t run_op[11] = {
	{";", run_semicolon},
	{"||", run_or},
	{"|", run_pipe},
	{"&&", run_and},
	{"<<<", NULL},
	{"<<", run_double_left_chevron},
	{"<", run_left_chevron},
	{">>", run_double_right_chevron},
	{">", run_right_chevron},
	{"&", run_background},
	{NULL, NULL}
};

int	run_cmd(shell_t *shell, tree_t *tree);

// verification
int	verification_background(shell_t *shell, tree_t *node);

int	verification_left_chevron(shell_t *shell, tree_t *node);

int	verification_double_left_chevron(shell_t *shell, tree_t *node);

int	verification_right_chevron(shell_t *shell, tree_t *node);

int	verification_double_right_chevron(shell_t *shell, tree_t *node);

int	verification_right_chevron_ambigous_output(tree_t *node);

int	verification_or(shell_t *shell, tree_t *node);

int	verification_pipe(shell_t *shell, tree_t *node);

int	verification_pipe_ambigous_redirection(tree_t *node);

int	verification_and(shell_t *shell, tree_t *node);

int	verification_semicolon(shell_t *shell, tree_t *node);

static const optab_t verification_op[11] = {
	{";", verification_semicolon},
	{"||", verification_or},
	{"|", verification_pipe},
	{"&&", verification_and},
	{"<<<", NULL},
	{"<<", verification_double_left_chevron},
	{"<", verification_left_chevron},
	{">>", verification_double_right_chevron},
	{">", verification_right_chevron},
	{"&", verification_background},
	{NULL, NULL}
};
// execution

int	basic_exec(shell_t *shell, char **cmd);

// autocomplétion

char	*auto_completion(char *str);

#endif
