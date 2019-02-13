/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include "variable.h"

Test(create_variable, fail)
{
	variable_t *var = create_variable(NULL, "helloo");

	cr_assert_eq(var, NULL);
}

Test(create_variable, success)
{
	variable_t *var = create_variable("flonflon", "helloo");

	cr_assert_neq(var, NULL);
	cr_assert_str_eq(var->name, "flonflon");
	cr_assert_str_eq(var->data, "helloo");
}
Test(create_variable, success2)
{
	variable_t *var = create_variable("flonflon", NULL);

	cr_assert_neq(var, NULL);
	cr_assert_str_eq(var->name, "flonflon");
	cr_assert_eq(var->data, NULL);
}
