/*
** EPITECH PROJECT, 2017
** hm_generate_object
** File description:
** hm_generate_object
*/

#include <stdlib.h>
#include "hash_map.h"
#include "my.h"

hm_object_t	*hm_generate_object(char *name, void *data)
{
	hm_object_t *obj;

	if (name == NULL || (obj = malloc(sizeof(*obj))) == NULL)
		return (NULL);
	obj->key = my_strdup(name);
	obj->data = data;
	obj->next = NULL;
	return (obj);
}
