/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include "header_shell.h"

Test(verification_and, test1)
{
	tree_t tree = {.left = NULL, .right = NULL};
	tree_t right;

	cr_assert_eq(verification_and(NULL, &tree), 1);
	tree.right = &right;
	cr_assert_eq(verification_and(NULL, &tree), 0);
}
