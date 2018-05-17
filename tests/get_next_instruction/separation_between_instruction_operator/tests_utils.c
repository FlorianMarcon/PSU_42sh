/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include "my.h"
#include "header_shell.h"

Test(new_str, test1)
{
	char *str = my_strdup("ls>>toto");
	char *new = new_str(str, 2, ">>");

	cr_assert_neq(new, NULL);
	cr_assert_str_eq(new, "ls >> toto");
}

Test(new_str, test2)
{
	char *str = my_strdup("ls>>");
	char *new = new_str(str, 2, ">>");

	cr_assert_neq(new, NULL);
	cr_assert_str_eq(new, "ls >> ");
}

Test(operator_is_present, test1)
{
	cr_assert_str_eq(operator_is_present(">>oe"), ">>");
	cr_assert_str_eq(operator_is_present(">oe"), ">");
	cr_assert_eq(operator_is_present("z>>oe"), NULL);
}

Test(separation_between_instruction_operator, test1)
{
	char *str = my_strdup(">>salut; ca va |");
	char *res = separation_between_instruction_operator(str);

	cr_assert_neq(res, NULL);
	cr_assert_str_eq(res, " >> salut ;  ca va  | ");
}
