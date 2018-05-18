/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** len
*/

#include "header_shell.h"

int	len_env_list(env_t *list)
{
	int i = 0;

	while (list->next != NULL) {
		list = list->next;
		i++;
	}
	return (i + 1);
}

int	my_str_char_len(char *cmd, char sep)
{
	int i = -1;

	while (str[++i] != '\0' && str[i] != sep);
	return (i);
}
