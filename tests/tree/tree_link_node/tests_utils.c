/*
** EPITECH PROJECT, 2017
** tree_link_node
** File description:
** tree_link_node
*/

#include <criterion/criterion.h>
#include "tree.h"

Test(tree_link_node, test1)
{
	tree_t tree;
	tree_t right;

	tree_link_node(&tree, &right, NULL);
	cr_assert_neq(tree.right, NULL);
}
