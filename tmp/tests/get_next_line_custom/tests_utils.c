/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "get_next_line_custom.h"

Test(gnl_delete_char, test1)
{
	char *str = strdup("Hello World!");

	cr_redirect_stdout();
	cr_assert_str_eq(gnl_delete_char(str), "Hello World");
	cr_assert_stdout_eq_str("\b \b");
	str[0] = '\0';
	cr_assert_str_eq(gnl_delete_char(str), "\0");
}
