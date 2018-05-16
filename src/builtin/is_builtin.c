/*
** EPITECH PROJECT, 2017
** is_builtin
** File description:
** is_builtin
*/

#include "header_shell.h"

bool	is_builtin(char *cmd)
{
	if (cmd == NULL)
		return (false);
	for (unsigned int i = 0; builtin[i].label != NULL; i++)
		if (my_strcmp(builtin[i].label, cmd) == 0)
			return (true);
	return (false);
}
