/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include "header_shell.h"

Test(verification_or, test1)
{
	tree_t tree = {.left = NULL, .right = NULL};
	tree_t right;

	cr_assert_eq(verification_or(NULL, &tree), 1);
	tree.right = &right;
	cr_assert_eq(verification_or(NULL, &tree), 1);
	tree.left = &right;
	cr_assert_eq(verification_or(NULL, &tree), 0);
}
