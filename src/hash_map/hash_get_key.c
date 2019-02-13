/*
** EPITECH PROJECT, 2017
** hash_get_key
** File description:
** hash_get_key
*/

#include <unistd.h>
#include "hash_map.h"

int	hm_get_key(char *str, hash_map_t *hm)
{
	int i = 0;
	int key = 0;

	if (str == NULL || hm == NULL)
		return (-1);
	while (str[i] != '\0')
		key += str[i++];
	key = key % hm->size;
	return (key);
}
