/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include "header_shell.h"

Test(verification_semicolon, test)
{
	cr_assert_eq(verification_semicolon(NULL, NULL), 0);
}
