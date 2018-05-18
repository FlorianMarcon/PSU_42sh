/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include "header_shell.h"

Test(is_builtin, test)
{
	cr_assert_eq(is_builtin("aaaaaa"), false);
	cr_assert_eq(is_builtin("exit"), true);
	cr_assert_eq(is_builtin(NULL), false);
}
