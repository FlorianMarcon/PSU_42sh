/*
** EPITECH PROJECT, 2017
** verification
** File description:
** verification
*/

#include "header_shell.h"

int	verification_right_chevron_ambigous_output(tree_t *node)
{
	tree_t *right = node->right;
	char *op;

	if (right == NULL || right->data == NULL)
		return (0);
	op = operator_is_present(((char **)right->data)[0]);
	if (op != NULL && (my_strcmp(op, ">") == 0 || my_strcmp(op, ">>") == 0
						|| my_strcmp(op, "|") == 0)) {
		fprintf(stderr, "%s\n", "Ambiguous output redirect.");
		return (1);
	}
	return (0);
}
int	verification_right_chevron(shell_t *shell, tree_t *node)
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
	if (verification_right_chevron_ambigous_output(node))
		return (1);
	return (0);
}

int	verification_double_right_chevron(shell_t *shell, tree_t *node)
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
	if (verification_right_chevron_ambigous_output(node))
		return (1);
	return (0);
}
