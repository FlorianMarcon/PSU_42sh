/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_tabdup, test1)
{
	char *old[] = {
		"salut",
		"toi",
		NULL
	};
	char **tab = my_tabdup(old);
	cr_assert_neq(tab, NULL);
	cr_assert_neq(tab[0], NULL);
	cr_assert_neq(tab[1], NULL);
	cr_assert_str_eq(tab[0], old[0]);
	cr_assert_str_eq(tab[1], old[1]);
	cr_assert_eq(tab[2], NULL);
	cr_assert_eq(my_tabdup(NULL), NULL);
}
