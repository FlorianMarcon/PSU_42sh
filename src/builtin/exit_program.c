/*
** EPITECH PROJECT, 2017
** exit
** File description:
** exit
*/

#include "header_shell.h"
#include "my.h"

int	exit_program(shell_t *shell, char **cmd)
{
	if (len_tab(cmd) > 2)
		return (1);
	shell->exit = true;
	if (len_tab(cmd) == 2)
		shell->value_exit = my_getnbr(cmd[1]);
	return (0);
}
