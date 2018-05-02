/*
** EPITECH PROJECT, 2017
** minishell2
** File description:
** is_built_in
*/

#include "header_shell.h"

void	env(shell_t *shell, char **cmd)
{
	if (cmd == NULL)
		return;
	while (shell->env != NULL) {
		my_putstr(shell->env->data);
		my_putchar('\n');
		shell->env = shell->env->next;
	}
}
