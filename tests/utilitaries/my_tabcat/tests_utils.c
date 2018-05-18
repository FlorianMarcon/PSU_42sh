/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include "header_shell.h"

Test(my_tabcat, test1)
{
	char *fir[] = {
		"Hello",
		"YES",
		NULL
	};
	char *sec[] = {
		"Salut",
		"OUI",
		NULL
	};
	char **new = my_tabcat(fir, sec);

	cr_assert_neq(new, NULL);
	cr_assert_str_eq(new[0], fir[0]);
	cr_assert_str_eq(new[1], fir[1]);
	cr_assert_str_eq(new[2], sec[0]);
	cr_assert_str_eq(new[3], sec[1]);
	cr_assert_eq(new[4], NULL);
}
