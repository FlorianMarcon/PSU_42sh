/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "header_shell.h"
#include "hash_map.h"

Test(auto, test1)
{
	char str[]="cd /test/ab";

	cr_assert_str_eq(auto_completion(str), "/test/ab");
}
