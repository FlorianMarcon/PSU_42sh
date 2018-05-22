/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include "header_shell.h"

Test(my_char_ispresent, test1)
{
	cr_assert_eq(my_char_ispresent(NULL, 'c'), 0);
	cr_assert_eq(my_char_ispresent("NULL", 'c'), 0);
	cr_assert_eq(my_char_ispresent("il est présent c", 'c'), 1);
}
