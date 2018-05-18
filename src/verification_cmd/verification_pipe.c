/*
** EPITECH PROJECT, 2017
** verification
** File description:
** verification
*/

#include "header_shell.h"

int	verification_pipe_ambigous_redirection(tree_t *node)
{
	char **tab;
	char *op;

	while (node != NULL) {
		tab = node->data;
		if (tab != NULL && (op = operator_is_present(tab[0])) != NULL) {
			if (my_strcmp(op, "<") == 0 || my_strcmp(op, "<<") == 0 ) {
				fprintf(stderr, "%s\n", "Ambiguous input redirect.");
				return (1);
			}
		}
		node = node->right;
	}
	return (0);
}
int	verification_pipe(shell_t *shell, tree_t *node)
{
	(void)shell;
	if (node->right == NULL || node->left == NULL) {
		fprintf(stderr, "%s\n", "Invalid null command.");
		return (1);
	}
	if (verification_pipe_ambigous_redirection(node))
		return (1);
	return (0);
}
