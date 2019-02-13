/*
** EPITECH PROJECT, 2017
** search_operator
** File description:
** search_operator
*/

#include "my.h"
#include "binary.h"
#include "header_shell.h"

int	search_index_operator(char **cmd)
{
	int i = 0;

	if (cmd == NULL)
		return (-1);
	while (cmd[i] != NULL) {
		if (my_strcmp(cmd[i++], ";") == 0)
			return (--i);
	}
	i = 0;
	while (cmd[i] != NULL) {
		if (my_strcmp(cmd[i++], "|") == 0)
			return (--i);
	}
	i = 0;
	while (cmd[i] != NULL) {
		if (is_operator(cmd[i]))
			return (i);
		i++;
	}
	return (-1);
}
