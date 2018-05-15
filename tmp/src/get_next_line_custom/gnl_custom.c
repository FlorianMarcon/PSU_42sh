/*
** EPITECH PROJECT, 2017
** gnl_custom
** File description:
** gnl_custom
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "gnl_custom.h"
#include "my.h"

char	*gnl_treatement(char *str, char *new, unsigned int *index)
{
	char *tmp = NULL;
	char *var = str;

	for (unsigned int i = 0; gnl_builtin[i].label != 0; i++) {
		if (new[0] == gnl_builtin[i].label) {
			str = gnl_builtin[i].ptr(str, index);
			return (str);
		}
	}
	dprintf(1, "\033[%luD\033[K", strlen(str));
	tmp = my_strcat(new, &str[*index]);
	str[*index] = '\0';
	str = my_strcat(str, tmp);
	dprintf(1, "%s", str);
	if ((*index = *index + 1) != strlen(str))
		dprintf(1, "\033[%luD",strlen(str) - *index);
	free(var);
	return (str);
}
char	*gnl_custom(void)
{
	char *str = malloc(sizeof(*str));
	char new[2] = " \0";
	int count = 0;
	unsigned int index = 0;

	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	while ((count = read(0, new, 1)) != -1 && new[0] != '\n')
		str = gnl_treatement(str, new, &index);
	if (str != NULL)
		return (str);
	return (NULL);
}
