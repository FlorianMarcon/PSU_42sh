/*
** EPITECH PROJECT, 2017
** unset_local
** File description:
** unset_local
*/

#include <criterion/criterion.h>
#include "header_shell.h"
#include "variable.h"

Test(destroy_local_variable, test1)
{
	variable_t *first = create_variable("flonflon", "12");
	variable_t *second = create_variable("last", NULL);
	linked_list_t *list = create_list(first);

	create_node(list, second);
	cr_assert_neq(list, NULL);
	cr_assert_neq(list->next, NULL);
	destroy_local_variable(&list, second);
	cr_assert_eq(list->next, NULL);
	destroy_local_variable(&list, first);
	cr_assert_eq(list, NULL);
}

Test(unset_local, test1)
{
	shell_t shell = {.list_local = NULL};
	char *cmd[5] = {
		"set",
		"fl",
		"=",
		"12",
		NULL
	};
	set_local(&shell, cmd);
	cr_assert_neq(shell.list_local, NULL);
	cmd[0] = strdup("unset");
	cmd[1] = strdup("test");
	cmd[2] = NULL;
	unset_local(&shell, cmd);
	cr_assert_neq(shell.list_local, NULL);
	cmd[1] = strdup("fl");
	unset_local(&shell, cmd);
	cr_assert_eq(shell.list_local, NULL);
}
