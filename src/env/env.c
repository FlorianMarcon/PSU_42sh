/*
** EPITECH PROJECT, 2017
** minishell2
** File description:
** is_built_in
*/

#include "env.h"

void	env(shell_t *shell, char **cmd)
{
	linked_list_t *envp = shell->list_env;
	while (envp != NULL) {
		my_putstr(envp->data);
		my_putchar('\n');
		envp = envp->next;
	}
}
