/*
** EPITECH PROJECT, 2017
** repeat
** File description:
** repeat
*/

#include "header_shell.h"

int	repeat(shell_t *shell, char **cmd)
{
	int nb;

	if (len_tab(cmd) <= 2) {
		fprintf(stderr, "repeat: Too few arguments.\n");
		return (1);
	} else if (my_str_isnum(cmd[1]) == 0) {
		fprintf(stderr, "repeat: Badly formed number.\n");
		return (1);
	} else {
		nb = atoi(cmd[1]);
		for (int i = 0; i != nb; i++)
			basic_exec(shell, &cmd[2]);
	}
	return (0);
}
