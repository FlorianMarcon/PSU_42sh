/*
** EPITECH PROJECT, 2017
** analyse_file
** File description:
** analyse_file
*/

#include "header_shell.h"
#include "binary.h"

void	analyse_file(hash_map_t *hm, char *path, char *cmd)
{
	char *cat = my_strcat(path, "/");

	cat = my_strcat(cat, cmd);

	if (is_executable(cat)) {
		put_binary_in_hm(hm, path, cmd);
	}
}
