/*
** EPITECH PROJECT, 2017
** hm_get_last_object
** File description:
** hm_get_last_object
*/

#include "hash_map.h"

hm_object_t	*hm_get_last_object(hm_object_t *hm)
{
	if (hm == NULL)
		return (NULL);
	while (hm->next != NULL)
		hm = hm->next;
	return (hm);
}
