/*
** EPITECH PROJECT, 2017
** get_path
** File description:
** get_path
*/

#include "my.h"
#include "hash_map.h"

char	*get_path(hash_map_t *env, char *cmd)
{
	hm_object_t *obj = hm_get_object(env, cmd);
	char *path;

	if (obj == NULL)
		return (cmd);
	path = (char *)obj->data;
	return (path);
}
