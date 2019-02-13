/*
** EPITECH PROJECT, 2017
** binary.h
** File description:
** binary.h
*/

#ifndef BINARY_
#define BINARY_

#include <dirent.h>
#include "hash_map.h"

typedef struct binary_s {
	char *cmd;
	char *path;
}binary_t;

// generate_hash_map_binary

void	put_binary_in_hm(hash_map_t *hm, char *path, char *cmd);

void	analyse_file(hash_map_t *hm, char *path, char *cmd);

void	hm_binary_list_all_file(hash_map_t *hm, DIR *dir, char *path);

hash_map_t	*generate_hm_binary(char *all_path);

#endif
