/*
** EPITECH PROJECT, 2017
**
** File description:
**
*/

#include "header_shell.h"

int	echo(shell_t *shell, char **cmd)
{
	(void)shell;
	for (unsigned int i = 1; cmd[i] != NULL; i++)
		dprintf(1, "%s", cmd[i]);
	dprintf(1, "\n");
	return (0);
}
