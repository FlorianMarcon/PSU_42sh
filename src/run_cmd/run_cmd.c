/*
** EPITECH PROJECT, 2017
** run_cmd
** File description:
** run_cmd
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "tree.h"
#include "header_shell.h"
#include "my.h"

int	search_and_run_builtin(shell_t *shell, char **cmd)
{
	if (cmd[0] == NULL)
		return (1);
	for (unsigned int i = 0; builtin[i].label != NULL; i++) {
		if (my_strcmp(cmd[0], builtin[i].label) == 0) {
			builtin[i].ptr(shell, cmd);
			return (0);
		}
	}
	return (1);
}

int	run_operator(shell_t *shell, tree_t *tree, char **cmd)
{
	for (unsigned int i = 0; run_op[i].label != NULL; i++) {
		if (my_strcmp(run_op[i].label, cmd[0]) == 0 &&
						run_op[i].ptr != NULL) {
			run_op[i].ptr(shell, tree);
			return (0);
		}
	}
	return (0);
}

char	**preexecution(char **tab, shell_t *shell)
{
	for (unsigned int i = 0; tab[i] != NULL; i++) {
		tab[i] = parsing_change_variable(tab[i], shell);
	}
	tab = parsing_change_alias(shell->list_alias, tab);
	return (tab);
}

int	run_cmd(shell_t *shell, tree_t *tree)
{
	char **tab;

	if (tree == NULL || (tab = (char **)(tree->data)) == NULL)
		return (1);
	if (is_operator(tab[0])) {
		run_operator(shell, tree, tab);
	} else {
		tab = preexecution(tab, shell);
		tree->data = tab;
		if (search_and_run_builtin(shell, tab))
			shell->value_exit = basic_exec(shell, tab);
	}
	return (0);
}
