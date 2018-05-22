/*
** EPITECH PROJECT, 2017
** hash_table
** File description:
** hash_table
*/

#ifndef HASH_TABLE_
#define HASH_TABLE_

#define SIZE_HM 3000

#include "my.h"
#include "hash_map.h"

typedef struct hm_object {
	char *key;
	void *data;
	struct hm_object *next;
}hm_object_t;

typedef struct hash_map {
	hm_object_t **hash_map;
	int size;
}hash_map_t;

hash_map_t	*generate_hash_map(int size);

hm_object_t	*hm_generate_object(char *name, void *data);

int	hm_get_key(char *str, hash_map_t *hm);

hm_object_t	*hm_get_last_object(hm_object_t *hm);

void	hm_add_object(hash_map_t *hm, char *name, void *data);

hm_object_t	*hm_get_object(hash_map_t *hm, char *label);

void	hm_destroy(hash_map_t *hm);

#endif
