/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include "variable.h"
#include "header_shell.h"
Test(create_variable_local, success)
{
	shell_t shell = {.list_local = NULL};
	char *cmd[4] = {
		"flonflon",
		"=",
		"better",
		NULL
	};
	unsigned int i = 0;

	create_variable_local(&shell, cmd, &i);
	cr_assert_neq(shell.list_local, NULL);
	cr_assert_str_eq(((variable_t *)shell.list_local->data)->name,
								"flonflon");
	cr_assert_str_eq(((variable_t *)shell.list_local->data)->data,
								"better");
	cmd[1] = cmd[2];
	create_variable_local(&shell, cmd, &i);

}
Test(create_variable_local, fail)
{
	shell_t shell = {.list_local = NULL};
	char *cmd[1] = {
		NULL
	};
	unsigned int i = 0;
	create_variable_local(&shell, cmd, &i);

	cr_assert_eq(shell.list_local, NULL);
}

Test(set_local, success)
{
	shell_t shell = {.list_local = NULL};
	char *cmd[5] = {
		"set",
		"flonflon",
		"=",
		"test",
		NULL
	};
	variable_t *var;
	cr_assert_eq(set_local(&shell, cmd), 0);
	var = (variable_t *)shell.list_local->data;
	cr_assert_str_eq(var->name, "flonflon");
	cr_assert_str_eq(var->data, "test");
	cmd[3] = strdup("hello");
	cr_assert_eq(set_local(&shell, cmd), 0);
	var = (variable_t *)shell.list_local->data;
	cr_assert_str_eq(var->name, "flonflon");
	cr_assert_str_eq(var->data, "hello");
}
