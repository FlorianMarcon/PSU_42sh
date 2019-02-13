/*
** EPITECH PROJECT, 2017
** verification_cmd
** File description:
** verification_cmd
*/

#include "header_shell.h"
#include "tree.h"
#include "my.h"

int	verif_error(tree_t *tree)
{
	char **cmd = (char **)tree->data;
	char *op = operator_is_present(cmd[0]);

	for (unsigned int i = 0; verification_op[i].label != NULL; i++) {
		if (my_strcmp(op, verification_op[i].label) == 0)
			return (verification_op[i].ptr(NULL, tree));
	}
	return (0);
}
int	verification_cmd(tree_t *node)
{
	int a = 0;

	if (node == NULL || is_operator(((char **)node->data)[0]) == 0)
		return (0);
	else if (verif_error(node))
		return (1);
	else {
		a += verification_cmd(node->left);
		a += verification_cmd(node->right);
	}
	if (a != 0)
		return (1);
	return (0);
}
