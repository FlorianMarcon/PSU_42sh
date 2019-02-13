/*
** EPITECH PROJECT, 2017
** run_and_or
** File description:
** run_and_or
*/

#include "header_shell.h"

int	run_and(shell_t *shell, tree_t *tree)
{
	if (tree->right == NULL) {
		fprintf(stderr, "Invalid null command.\n");
		shell->value_exit = 1;
		return (1);
	}
	run_cmd(shell, tree->left);
	if (shell->value_exit == 0)
		run_cmd(shell, tree->right);
	return (0);
}
int	run_or(shell_t *shell, tree_t *tree)
{
	if (tree->right == NULL) {
		fprintf(stderr, "Invalid null command.\n");
		shell->value_exit = 1;
		return (1);
	}
	run_cmd(shell, tree->left);
	if (shell->value_exit != 0)
		run_cmd(shell, tree->right);
	return (0);
}
