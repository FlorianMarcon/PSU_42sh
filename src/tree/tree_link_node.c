/*
** EPITECH PROJECT, 2017
** tree_link_node
** File description:
** tree_link_node
*/

#include <stdlib.h>
#include "tree.h"

void	tree_link_node(tree_t *node, tree_t *right, tree_t *left)
{
	if (node == NULL)
		return;
	node->right = right;
	node->left = left;
}
