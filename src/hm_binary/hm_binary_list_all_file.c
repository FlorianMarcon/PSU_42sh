/*
** EPITECH PROJECT, 2017
** hm_binary_list_all_file
** File description:
** hm_binary_list_all_file
*/

#include <dirent.h>
#include "header_shell.h"
#include "hash_map.h"
#include "binary.h"

void	hm_binary_list_all_file(hash_map_t *hm, DIR *dir, char *path)
{
	struct dirent *obj;

	while ((obj = readdir(dir)) != NULL) {
		if (obj->d_type == DT_REG)
			analyse_file(hm, path, obj->d_name);
	}
}
