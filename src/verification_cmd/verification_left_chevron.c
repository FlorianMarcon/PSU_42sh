/*
** EPITECH PROJECT, 2017
** verification
** File description:
** verification
*/

#include "header_shell.h"

int	verification_left_chevron(shell_t *shell, tree_t *node)
{
	(void)shell;
	if (node->right == NULL) {
		fprintf(stderr, "%s\n","Missing name for redirect.");
		return (1);
	}
	if (node->left == NULL) {
		fprintf(stderr, "%s\n","Invalid null command.");
		return (1);
	}
	return (0);
}

int	verification_double_left_chevron(shell_t *shell, tree_t *node)
{
	(void)shell;
	if (node->right == NULL) {
		fprintf(stderr, "%s\n","Missing name for redirect.");
		return (1);
	}
	if (node->left == NULL) {
		fprintf(stderr, "%s\n","Invalid null command.");
		return (1);
	}
	return (0);
	return (0);
}
