/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include "variable.h"

Test(add_data_in_list, fail)
{
	linked_list_t list = {.next = NULL};

	add_data_in_list(NULL, NULL, &list);
	cr_assert_eq(list.next, NULL);
	add_data_in_list("NULL", NULL, NULL);
	cr_assert_eq(list.next, NULL);
}
Test(add_data_in_list, success)
{
	linked_list_t list = {.next = NULL};
	variable_t *var;

	add_data_in_list("FLOFLO", "BEST", &list);
	cr_assert_neq(list.next, NULL);
	var = (variable_t *)list.next->data;
	cr_assert_neq(var, NULL);
	cr_assert_str_eq(var->name, "FLOFLO");
	cr_assert_str_eq(var->data, "BEST");
	add_data_in_list("FLOFLO", "WORSE", &list);
	cr_assert_neq(list.next, NULL);
	cr_assert_eq(list.next->next, NULL);
	var = (variable_t *)list.next->data;
	cr_assert_neq(var, NULL);
	cr_assert_str_eq(var->name, "FLOFLO");
	cr_assert_str_eq(var->data, "WORSE");
}
