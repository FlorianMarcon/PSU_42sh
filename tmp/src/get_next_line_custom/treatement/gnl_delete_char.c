/*
** EPITECH PROJECT, 2017
** gnl_delete_char
** File description:
** gnl_delete_char
*/

#include <string.h>
#include <stdio.h>
#include "my.h"

char	*gnl_delete_char(char *str, unsigned int *index)
{
	char *var = str;

	if (*index == 0)
		return (str);
	dprintf(1, "\033[%luD\033[K", strlen(str));
	str[*index - 1] = '\0';
	str = my_strcat(str, &str[*index]);
	dprintf(1, "%s", str);
	*index = *index - 1;
	if (*index != strlen(str))
		dprintf(1, "\033[%luD", strlen(str) - *index);
	free(var);
	return (str);
}
