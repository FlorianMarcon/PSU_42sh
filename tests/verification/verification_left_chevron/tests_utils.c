/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include "header_shell.h"

Test(verification_left_chevron, test)
{
	tree_t node = {NULL, NULL, NULL};
	tree_t right;

	cr_assert_eq(verification_left_chevron(NULL, &node), 1);
	node.right = &right;
	cr_assert_eq(verification_left_chevron(NULL, &node), 1);
	node.left = &right;
	cr_assert_eq(verification_left_chevron(NULL, &node), 0);
}
Test(verification_double_left_chevron, test)
{
	tree_t node = {NULL, NULL, NULL};
	tree_t right;

	cr_assert_eq(verification_double_left_chevron(NULL, &node), 1);
	node.right = &right;
	cr_assert_eq(verification_double_left_chevron(NULL, &node), 1);
	node.left = &right;
	cr_assert_eq(verification_double_left_chevron(NULL, &node), 0);
}
