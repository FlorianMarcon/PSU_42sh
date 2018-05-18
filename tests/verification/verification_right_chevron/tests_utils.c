/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include "header_shell.h"

Test(verification_right_chevron, test)
{
	tree_t node = {NULL, NULL, NULL};
	tree_t right;

	cr_assert_eq(verification_right_chevron(NULL, &node), 1);
	node.right = &right;
	cr_assert_eq(verification_right_chevron(NULL, &node), 1);
	node.left = &right;
	cr_assert_eq(verification_right_chevron(NULL, &node), 0);
}
Test(verification_double_right_chevron, test)
{
	tree_t node = {NULL, NULL, NULL};
	tree_t right;

	cr_assert_eq(verification_double_right_chevron(NULL, &node), 1);
	node.right = &right;
	cr_assert_eq(verification_double_right_chevron(NULL, &node), 1);
	node.left = &right;
	cr_assert_eq(verification_double_right_chevron(NULL, &node), 0);
}

Test(verification_right_chevron_ambigous_output, test)
{
	char *tab[5] = {
		">",
		">>",
		"|",
		"<",
		NULL
	};
	tree_t node = {NULL, NULL, NULL};
	tree_t right = {(void *)tab, NULL, NULL};

	cr_assert_eq(verification_right_chevron_ambigous_output(&node), 0);
	node.right = &right;
	cr_assert_eq(verification_right_chevron_ambigous_output(&node), 1);
	right.data = (void *)(&tab[1]);
	cr_assert_eq(verification_right_chevron_ambigous_output(&node), 1);
	right.data = (void *)(&tab[2]);
	cr_assert_eq(verification_right_chevron_ambigous_output(&node), 1);
	right.data = (void *)(&tab[3]);
	cr_assert_eq(verification_right_chevron_ambigous_output(&node), 0);
}
