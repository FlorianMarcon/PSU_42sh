/*
** EPITECH PROJECT, 2017
** insert_object_in_hashmap
** File description:
** insert_object_in_hashmap
*/

#include "hash_map.h"

void	hm_add_object(hash_map_t *hm, char *name, void *data)
{
	int key;
	hm_object_t *obj;

	if (name == NULL || hm == NULL)
		return;
	key = hm_get_key(name, hm);
	obj = hm->hash_map[key];
	if (obj == NULL)
		hm->hash_map[key] = hm_generate_object(name, data);
	else {
		obj = hm_get_last_object(obj);
		obj->next = hm_generate_object(name, data);
	}
}
