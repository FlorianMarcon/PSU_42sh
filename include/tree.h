/*
** EPITECH PROJECT, 2017
** tree
** File description:
** tree
*/

#ifndef TREE_
#define TREE_

typedef struct tree_s {
	void *data;

	struct tree_s *left;
	struct tree_s *right;
}tree_t;

tree_t	*tree_create_node(void *data, tree_t *right, tree_t *left);

void	tree_link_node(tree_t *node, tree_t *right, tree_t *left);

void	destroy_tree(tree_t *tree);

#endif
