/*
** EPITECH PROJECT, 2017
** hm_get_object
** File description:
** hm_get_object
*/

#include "hash_map.h"

hm_object_t	*hm_get_object(hash_map_t *hm, char *label)
{
	int key;
	hm_object_t *obj;

	if (hm == NULL || label == NULL)
		return (NULL);
	key = hm_get_key(label, hm);
	obj = hm->hash_map[key];
	while (obj != NULL) {
		if (my_strcmp(obj->key, label) == 0)
			return (obj);
		obj = obj->next;
	}
	return (NULL);
}
