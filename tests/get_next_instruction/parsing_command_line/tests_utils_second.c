/*
** EPITECH PROJECT, 2017
** tests_utils_second
** File description:
** tests_utils_second
*/

#include <criterion/criterion.h>
#include "header_shell.h"

Test(parsing_str, test1)
{
	char **tab = parsing_str(my_strdup("test | "), ' ' | '\t');
	tree_t *tree = parsing_command_line(tab);

	cr_assert_neq(tree, NULL);
	cr_assert_neq(tree->left, NULL);
	cr_assert_eq(tree->right, NULL);
}
