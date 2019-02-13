/*
** EPITECH PROJECT, 2017
** gnl_arrow
** File description:
** gnl_arrow
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "gnl_custom.h"

char	*gnl_special(char *str, unsigned int *index, shell_t *sh)
{
	char new[2] = " \0";

	if (read(0, new, 1) == -1)
		return (str);
	for (unsigned int i = 0; gnl_special_builtin[i].label != 0; i++) {
		if (new[0] == gnl_special_builtin[i].label) {
			str = gnl_special_builtin[i].ptr(str, index, sh);
			return (str);
		}
	}
	return (str);
}
