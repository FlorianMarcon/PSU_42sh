/*
** EPITECH PROJECT, 2017
** hm_destroy_object
** File description:
** hm_destroy_object
*/

#include <stdlib.h>
#include "hash_map.h"

void	hm_destroy_list_object(hm_object_t *obj)
{
	hm_object_t *next;

	if (obj == NULL)
		return;
	next = obj->next;
	free(obj->key);
	free(obj);
	hm_destroy_list_object(next);
}

void	hm_destroy(hash_map_t *hm)
{
	if (hm == NULL)
		return;
	for (int i = 0; i != hm->size; i++)
		hm_destroy_list_object(hm->hash_map[i]);
	free(hm->hash_map);
	free(hm);
}
