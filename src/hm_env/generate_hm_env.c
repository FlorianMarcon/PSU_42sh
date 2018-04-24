/*
** EPITECH PROJECT, 2017
** generate_hm_env
** File description:
** generate_hm_env
*/

#include "environment.h"
#include "hash_map.h"
#include "my_printf.h"
#include "my.h"

hash_map_t	*generate_hm_env(linked_list_t *list)
{
	hash_map_t *hm = generate_hash_map(SIZE_HM);
	variable_t *var;

	if (hm == NULL)
		return (NULL);
	while (list != NULL) {
		var = (variable_t *)list->data;
		if (var != NULL)
			hm_add_object(hm, var->name, var->data);
		list = list->next;
	}
	return (hm);
}
