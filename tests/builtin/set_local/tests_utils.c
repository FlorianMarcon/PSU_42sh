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
	char *cmd[4] = {
		"flonflon",
		"=",
		"better",
		NULL
	};
	unsigned int i = 0;
	variable_t *var = create_variable_local(cmd, &i);

	cr_assert_neq(var, NULL);
	cr_assert_str_eq(var->name, "flonflon");
	cr_assert_str_eq(var->data, "better");
	cmd[1] = cmd[2];
	var = create_variable_local(cmd, &i);
	cr_assert_neq(var, NULL);
	cr_assert_eq(var->data, NULL);

}
Test(create_variable_local, fail)
{
	char *cmd[1] = {
		NULL
	};
	unsigned int i = 0;
	variable_t *var = create_variable_local(cmd, &i);

	cr_assert_eq(var, NULL);
}

Test(add_variable_list_local, test1)
{
	shell_t shell = {.list_local = NULL};
	variable_t var = {"flonflon", "test"};
	variable_t var2 = {"re", "sec"};
	add_variable_list_local(&shell, &var);
	cr_assert_neq(shell.list_local, NULL);
	cr_assert_eq(shell.list_local->data, &var);
	add_variable_list_local(&shell, &var2);
	cr_assert_neq(shell.list_local->next, NULL);
	cr_assert_eq(shell.list_local->next->data, &var2);

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
