/*
** EPITECH PROJECT, 2017
** generate_hm_binary
** File description:
** generate_hm_binary
*/

#include <sys/types.h>
#include <dirent.h>
#include "hash_map.h"
#include "binary.h"

hash_map_t	*generate_hm_binary(char *all_path)
{
	char **tab;
	hash_map_t *map = generate_hash_map(SIZE_HM);
	DIR *dir;

	if (map == NULL)
		return (NULL);
	if (all_path == NULL || (tab = parsing_str(all_path, ':')) == NULL)
		return (map);
	for (unsigned int i = 0; tab[i] != NULL; i++) {
		dir = opendir(tab[i]);
		if (dir != NULL) {
			hm_binary_list_all_file(map, dir, tab[i]);
			closedir(dir);
		}
	}
	return (map);
}
