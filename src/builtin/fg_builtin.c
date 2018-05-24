/*
** EPITECH PROJECT, 2017
** fg_builtin
** File description:
** fg_builtin
*/

#include "header_shell.h"

int	fg_builtin(shell_t *shell, char **cmd)
{
	linked_list_t *list = shell->process_back;

	(void)cmd;
	if (list == NULL) {
		fprintf(stderr, "fg: No current job.\n");
		return (1);
	}
	return (0);
}
