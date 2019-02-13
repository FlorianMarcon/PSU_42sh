/*
** EPITECH PROJECT, 2017
** tree_create_node
** File description:
** tree_create_node
*/

#include <stdlib.h>
#include "tree.h"

tree_t	*tree_create_node(void *data, tree_t *right, tree_t *left)
{
	tree_t *tree = malloc(sizeof(*tree));

	if (tree == NULL)
		return (NULL);
	tree->data = data;
	tree->right = right;
	tree->left = left;
	return (tree);
}
