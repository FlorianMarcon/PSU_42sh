/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include "variable.h"

Test(search_variable, test1)
{
	linked_list_t list[2] = {
		{&((variable_t){"floflo", "10"}), &list[1]},
		{&((variable_t){"last", "13"}), NULL}
	};

	cr_assert_eq(search_variable(NULL, list), NULL);
	cr_assert_eq(search_variable("Nothing", list), NULL);
	cr_assert_eq(search_variable("floflo", list), list[0].data);
	cr_assert_eq(search_variable("floflo", NULL), NULL);
}
