/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "header_shell.h"
#include "hash_map.h"

Test(env, test1)
{
	char *tab[] = {"PATH=/bin", "PWD=ici", NULL};
	shell_t shell = {.list_env = tab};
	char *cmd[] = {"env", "false", NULL};

	cr_redirect_stdout();
	cr_assert_eq(env(&shell, cmd), 1);
	cr_assert_stdout_eq_str("env: «false»: Aucun fichier ou dossier de ce\
 type\n");
}

Test(env, test2)
{
	char *tab[] = {"PATH=/bin", "PWD=ici", NULL};
	shell_t shell = {.list_env = tab};
	char *cmd[] = {"env", NULL};

	cr_redirect_stdout();
	cr_assert_eq(env(&shell, cmd), 0);
	cr_assert_stdout_eq_str("PATH=/bin\nPWD=ici\n");
}
