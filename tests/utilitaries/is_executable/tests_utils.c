/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include "header_shell.h"

Test(is_executable, test1)
{
	cr_assert_eq(is_executable("./data/executable"), 1);
	cr_assert_eq(is_executable("/bin/ls"), 1);
	cr_assert_eq(is_executable("./data/no_executable"), 0);
}
