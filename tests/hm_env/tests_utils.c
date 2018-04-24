/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include "environment.h"
#include "hash_map.h"
#include "my.h"

Test(generate_name_var_env, test1)
{
	cr_assert_eq(generate_name_var_env("SALUT"), NULL);
	cr_assert_str_eq(generate_name_var_env("PATH=salut"), "PATH");
}

Test(generate_arg_var_env, test1)
{
	linked_list_t *list = generate_arg_var_env("bonjour:florian:is:moi");

	cr_assert_neq(list, NULL);
	cr_assert_str_eq((char *)(list->data), "bonjour");
	list = list->next;
	cr_assert_str_eq((char *)(list->data), "florian");
	list = list->next;
	cr_assert_str_eq((char *)(list->data), "is");
	list = list->next;
	cr_assert_str_eq((char *)(list->data), "moi");
	list = list->next;
	cr_assert_eq(list, NULL);
}

Test(generate_hm_env, test1)
{
	char **envp = malloc(sizeof(*envp) * 3);
	hash_map_t *hm;
	int key;
	char *str;

	envp[0] = my_strdup("PATH=/bin:/usr/bin");
	envp[1] = my_strdup("TEST=var:oui");
	envp[2] = NULL;
	hm = generate_hm_env(envp);
	key = hm_get_key("PATH", hm);
	cr_assert_neq(hm, NULL);
	cr_assert_neq(hm->hash_map[key], NULL);
	cr_assert_str_eq(hm->hash_map[key]->key, "PATH");
	str = (char *)hm->hash_map[key]->data;
	cr_assert_neq(str, NULL);
	cr_assert_str_eq(str, "/bin:/usr/bin");
}
