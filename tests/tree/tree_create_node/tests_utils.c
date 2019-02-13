/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include "tree.h"

Test(tree_create_node, test1)
{
	char str[] = "criterion";
	tree_t *right = tree_create_node(str, NULL, NULL);
	tree_t *tree = tree_create_node(str, right, NULL);

	cr_assert_neq(tree, NULL);
	cr_assert_neq(tree->data, NULL);
	cr_assert_neq(tree->right, NULL);
	cr_assert_eq(tree->left, NULL);
}
