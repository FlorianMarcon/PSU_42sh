/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include "header_shell.h"
#include "tree.h"

Test(verification_cmd, success)
{
	char **tab = parsing_str(my_strdup("good  | test"), ' ' | '\t');
	tree_t *tree = parsing_command_line(tab);

	cr_assert_neq(tree, NULL);
	cr_assert_eq(verification_cmd(NULL), 0);
	cr_assert_eq(verification_cmd(tree), 0);
}

Test(verification_cmd, fail)
{
	char **tab = parsing_str(my_strdup("bad test  |"), ' ' | '\t');
	tree_t *tree = parsing_command_line(tab);

	cr_assert_neq(tree, NULL);
	cr_assert_eq(verification_cmd(tree), 1);
}
Test(verification_cmd, fail2)
{
	char **tab = parsing_str(my_strdup("echo \"ls\" | tcsh >"), ' ' | '\t');
	tree_t *tree = parsing_command_line(tab);

	cr_assert_neq(tree, NULL);
	cr_assert_eq(verification_cmd(tree), 1);
}
