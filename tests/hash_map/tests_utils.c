/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include <unistd.h>
#include "hash_map.h"

Test(hash_get_key, test1)
{
	hash_map_t hm = {.size = 1000};

	cr_assert_neq(hm_get_key("abc", &hm), -1);
	cr_assert_eq(hm_get_key(NULL, &hm), -1);
	cr_assert_eq(hm_get_key("abc", &hm), 294);
	hm.size = 100;
	cr_assert_eq(hm_get_key("abc", &hm), 94);
}

Test(generate_hash_map, test1)
{
	hash_map_t *hm = generate_hash_map(0);

	cr_assert_eq(hm, NULL);
	hm = generate_hash_map(12);
	cr_assert_neq(hm, NULL);
	cr_assert_eq(hm->size, 12);
}

Test(hm_generate_object, test1)
{
	hm_object_t *obj = hm_generate_object(NULL, NULL);

	cr_assert_eq(obj, NULL);
	obj = hm_generate_object("key", NULL);
	cr_assert_neq(obj, NULL);
	cr_assert_str_eq(obj->key, "key");
}

Test(hm_get_last_object, test1)
{
	hm_object_t *obj = hm_generate_object("first", NULL);

	cr_assert_neq(obj, NULL);
	obj->next = hm_generate_object("second", NULL);
	cr_assert_neq(obj->next, NULL);
	obj = hm_get_last_object(obj);
	cr_assert_str_eq(obj->key, "second");
	obj = hm_get_last_object(NULL);
	cr_assert_eq(obj, NULL);
}

Test(hm_add_object, test1)
{
	hash_map_t *hm = generate_hash_map(32);
	int key;

	cr_assert_neq(hm, NULL);
	key = hm_get_key("a", hm);
	hm_add_object(hm, "a", NULL);
	cr_assert_neq(hm->hash_map[key], NULL);
	cr_assert_eq(hm->hash_map[key + 1], NULL);
	cr_assert_eq(hm->hash_map[key]->next, NULL);
	hm_add_object(hm, "a", NULL);
	cr_assert_neq(hm->hash_map[key]->next, NULL);
}
