/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include "header_shell.h"

Test(get_path, test1)
{
	hash_map_t *hm = generate_hash_map(12);
	char *path = my_strdup("/bin/ls");
	hm_object_t *obj;
	char *tmp;

	cr_assert_neq(hm, NULL);
	hm_add_object(hm, "ls", path);
	obj = hm_get_object(hm, "ls");
	cr_assert_neq(obj, NULL);
	cr_assert_str_eq(obj->data, "/bin/ls");
	tmp = get_path(hm, "ls");
	cr_assert_neq(tmp, NULL);
	cr_assert_eq(tmp, obj->data);
	cr_assert_str_eq(tmp, "/bin/ls");
}
