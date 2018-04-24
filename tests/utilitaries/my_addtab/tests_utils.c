/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include "header_shell.h"

Test(my_addtab, test1)
{
	char *tab[] = {
		"first",
		"second",
		NULL
	};
	char **new = my_addtab(tab, "last");

	cr_assert_neq(new, NULL);
	cr_assert_str_eq(new[0], tab[0]);
	cr_assert_str_eq(new[1], tab[1]);
	cr_assert_str_eq(new[2], "last");
	cr_assert_eq(my_addtab(NULL, "test"), NULL);
}
