/*
** EPITECH PROJECT, 2017
** verification
** File description:
** verification
*/

#include "header_shell.h"

int	verification_and(shell_t *shell, tree_t *node)
{
	(void)shell;
	if (node->right == NULL) {
		fprintf(stderr, "%s\n", "Invalid null command.");
		return (1);
	}
	return (0);
}
