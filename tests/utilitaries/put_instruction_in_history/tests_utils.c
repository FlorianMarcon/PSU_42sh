/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include "header_shell.h"

Test(put_instruction_in_history, test1)
{
	shell_t shell = {.size_history = 3};

	for (unsigned int i = 0; i != shell.size_history; i++)
		shell.history[i] = NULL;
	put_instruction_in_history(&shell, "ls -l");
	cr_assert_neq(shell.history[0], NULL);
	cr_assert_str_eq(shell.history[0], "ls -l");
	cr_assert_eq(shell.history[1], NULL);
}

Test(put_instruction_in_history, test2)
{
	shell_t shell = {.size_history = 3};

	for (unsigned int i = 0; i != shell.size_history; i++)
		shell.history[i] = NULL;
	put_instruction_in_history(&shell, "ls -l");
	put_instruction_in_history(&shell, "ls -l");
	put_instruction_in_history(&shell, "ls -l");
	put_instruction_in_history(&shell, "FLONFLON");
	cr_assert_neq(shell.history[0], NULL);
	cr_assert_str_eq(shell.history[0], "FLONFLON");
	cr_assert_neq(shell.history[1], NULL);
}
Test(put_instruction_in_history, fail)
{
	shell_t shell = {.size_history = 3};

	for (unsigned int i = 0; i != shell.size_history; i++)
		shell.history[i] = NULL;
	put_instruction_in_history(NULL, "STR");
	put_instruction_in_history(&shell, NULL);
	cr_assert_eq(shell.history[0], NULL);
}
