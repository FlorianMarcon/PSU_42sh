/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include "header_shell.h"

Test(verification_pipe, test1)
{
	tree_t tree = {NULL, NULL, NULL};
	tree_t right = {NULL, NULL, NULL};

	cr_assert_eq(verification_pipe(NULL, &tree), 1);
	tree.right = &right;
	cr_assert_eq(verification_pipe(NULL, &tree), 1);
	tree.left = &right;
	cr_assert_eq(verification_pipe(NULL, &tree), 0);
}

Test(verification_pipe_ambigous_redirection, test1)
{
	char *tab[2] = {
		"<<",
		NULL
	};
	tree_t node = {(void*)tab, NULL, NULL};
	tree_t start = {NULL, NULL, NULL};

	cr_assert_eq(verification_pipe_ambigous_redirection(&start), 0);
	start.right = &node;
	cr_assert_eq(verification_pipe_ambigous_redirection(&start), 1);
}
