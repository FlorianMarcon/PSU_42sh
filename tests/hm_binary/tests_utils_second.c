/*
** EPITECH PROJECT, 2017
** tests_utils_second
** File description:
** tests_utils_second
*/

#include <criterion/criterion.h>
#include "hash_map.h"
#include "binary.h"

Test(generate_hm_binary, test1)
{
	hash_map_t *map = generate_hm_binary(NULL);

	cr_assert_neq(map, NULL);
}
