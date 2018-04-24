/*
** EPITECH PROJECT, 2017
** tests_utils_second
** File description:
** tests_utils_second
*/

#include <criterion/criterion.h>
#include "hash_map.h"

Test(hm_get_object, test1)
{
	hash_map_t *map = generate_hash_map(12);
	hm_object_t *obj;

	hm_add_object(map, "salut", NULL);
	obj = hm_get_object(map, "salut");
	cr_assert_neq(obj, NULL);
	obj = hm_get_object(map, "slut");
	cr_assert_eq(obj, NULL);
	obj = hm_get_object(NULL, "salut");
	cr_assert_eq(obj, NULL);
}
