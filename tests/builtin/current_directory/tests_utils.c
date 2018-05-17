/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "header_shell.h"

Test(current_directory, test)
{
	shell_t shell;
	char *envp[2] = {
		"PATH=/home/marcon/bin:/home/marcon/.local/bin:/usr/local/sbin:\
/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:\
/usr/games:/usr/local/games:/snap/bin",
		NULL
	};
	char *cmd[4] = {"cd", "../", "../", NULL};

	cr_assert_eq(generate_shell(envp, &shell), 0);
	cr_redirect_stderr();
	current_directory(&shell, cmd);
	cr_assert_stderr_eq_str("cd: Too many arguments.\n");
}
Test(current_directory, test2)
{
	shell_t shell;
	char *envp[2] = {
		"PATH=/home/marcon/bin:/home/marcon/.local/bin:/usr/local/sbin:\
/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:\
/usr/games:/usr/local/games:/snap/bin",
		NULL
	};
	char *cmd[4] = {"cd", "../falsefile", NULL};

	cr_assert_eq(generate_shell(envp, &shell), 0);
	cr_redirect_stderr();
	current_directory(&shell, cmd);
	cr_assert_stderr_eq_str("../falsefile: No such file or directory.\n");
}
