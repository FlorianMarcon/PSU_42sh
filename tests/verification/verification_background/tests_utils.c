/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include "header_shell.h"

Test(verification_background, test1)
{
	cr_assert_eq(verification_background(NULL, NULL), 0);
}
