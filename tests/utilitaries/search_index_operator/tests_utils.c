/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include "header_shell.h"

Test(is_operator, test1)
{
	cr_assert_eq(is_operator("<"), 1);
	cr_assert_eq(is_operator(">>"), 1);
	cr_assert_eq(is_operator("&"), 1);
	cr_assert_eq(is_operator("<a"), 0);
}

Test(search_index_operator, test1)
{
	char *cmd[] = {
		"&",
		"ls",
		"-l",
		"|",
		";",
		"cat",
		"file",
		NULL
	};
	cr_assert_eq(search_index_operator(cmd), 4);
	cmd[4] = NULL;
	cr_assert_eq(search_index_operator(cmd), 3);
	cmd[3] = NULL;
	cr_assert_eq(search_index_operator(cmd), 0);
	cr_assert_eq(search_index_operator(NULL), -1);
}
