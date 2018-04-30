/*
** EPITECH PROJECT, 2017
** exit
** File description:
** exit
*/

#include <stdio.h>
#include "header_shell.h"
#include "my.h"

int	exit_program(shell_t *shell, char **cmd)
{
	if (len_tab(cmd) > 2)
		return (1);
	shell->exit = true;
	if (len_tab(cmd) == 2) {
		if (my_str_isnum(cmd[1]))
			shell->value_exit = my_getnbr(cmd[1]);
		else if (atoi(cmd[1]) < 0)
			fprintf(stderr, "exit: Badly formed number.\n");
		else
			fprintf(stderr, "exit: Expression Syntax.\n");
	}
	return (0);
}
