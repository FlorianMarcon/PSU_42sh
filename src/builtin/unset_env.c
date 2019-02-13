/*
** EPITECH PROJECT, 2017
** unset_env
** File description:
** unset_env
*/

#include "header_shell.h"
#include "my.h"

int	unset_env(shell_t *shell, char **cmd)
{

	if (len_tab(cmd) == 1) {
		return (1);
	}
	for (unsigned int i = 1; cmd[i] != NULL; i++) {

	}
}
