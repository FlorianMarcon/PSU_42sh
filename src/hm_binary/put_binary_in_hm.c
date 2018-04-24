/*
** EPITECH PROJECT, 2017
** put_binary_in_hm
** File description:
** put_binary_in_hm
*/

#include "binary.h"
#include "hash_map.h"

void	put_binary_in_hm(hash_map_t *hm, char *path, char *cmd)
{
	path = my_strcat(path, "/");
	path = my_strcat(path, cmd);
	hm_add_object(hm, cmd, path);
}
