/*
** EPITECH PROJECT, 2017
** destroy_tree
** File description:
** destroy_tree
*/

#include <stdlib.h>
#include "tree.h"

void	destroy_tree(tree_t *tree)
{
	tree_t *left;
	tree_t *right;

	if (tree == NULL)
		return;
	left = tree->left;
	right = tree->right;
	if (tree->data != NULL)
		free (tree->data);
	free(tree);
	destroy_tree(left);
	destroy_tree(right);
}
