/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "header_shell.h"
#include "variable.h"

Test(search_variable_matching, test1)
{
	variable_t *first = create_variable("flonflon", "12");
	variable_t *second = create_variable("second", "2");
	linked_list_t *list = create_list(first);
	variable_t *tmp;

	create_node(list, second);
	cr_assert_neq(list, NULL);
	cr_assert_neq(list->next, NULL);
	tmp = search_variable_matching("flon", list);
	cr_assert_eq(tmp, NULL);
	tmp = search_variable_matching("secondisgood", list);
	cr_assert_eq(tmp, second);
}

Test(replace_variable, success)
{
	variable_t *first = create_variable("flonflon", "12");
	variable_t *second = create_variable("second", NULL);
	shell_t shell = {.list_local = create_list(first)};
	char *str = strdup("hello $flonflonbg");

	create_node(shell.list_local, second);
	cr_assert_neq(shell.list_local, NULL);
	cr_assert_neq(shell.list_local->next, NULL);
	cr_assert_str_eq(replace_variable(str, 6, &shell), "hello 12bg");
	str = strdup("hello $secondaa");
	cr_assert_str_eq(replace_variable(str, 6, &shell), "hello aa");
}

Test(replace_variable, failed)
{
	variable_t *first = create_variable("flonflon", "12");
	variable_t *second = create_variable("second", NULL);
	shell_t shell = {.list_local = create_list(first)};
	char *str = strdup("hello $noexist");

	create_node(shell.list_local, second);
	cr_assert_neq(shell.list_local, NULL);
	cr_assert_neq(shell.list_local->next, NULL);
	cr_redirect_stderr();
	cr_assert_eq(replace_variable(str, 6, &shell), NULL);
	cr_assert_stderr_eq_str("noexist: Undefined variable.\n");
}

Test(parsing_change_variable, test1)
{
	shell_t shell = {.list_local = NULL, .list_env = NULL};
	char *str = strdup("$flo");

	cr_assert_str_eq(parsing_change_variable("\\$flo", &shell), "\\$flo");
	cr_assert_eq(parsing_change_variable(str, &shell), NULL);
}
