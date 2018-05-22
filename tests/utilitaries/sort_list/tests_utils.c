/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include "header_shell.h"

Test(sort_list, test1)
{
	variable_t second = {"abcd", NULL};
	variable_t first = {"a", NULL};
	variable_t four = {"abcde", NULL};
	variable_t third = {"abcd", NULL};
	linked_list_t list[4] = {
		{&second, &list[1]},
		{&first, &list[2]},
		{&third, &list[3]},
		{&four, NULL}
	};

	sort_list(&list[0]);
	cr_assert_eq(list[0].data, &first);
	cr_assert_eq(list[1].data, &second);
	cr_assert_eq(list[2].data, &third);
	cr_assert_eq(list[3].data, &four);
}
Test(sort_list, test2)
{
	linked_list_t *list = NULL;

	sort_list(list);
}
