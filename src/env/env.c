/*
** EPITECH PROJECT, 2017
** minishell2
** File description:
** is_built_in
*/

#include "header_shell.h"

int	env(shell_t *shell, char **cmd)
{
	linked_list_t *envp = shell->list_env;
	if (envp == NULL)
		return (84);
	while (envp != NULL) {
		my_printf("%s=%s\n", (char *)envp->name, (char *)envp->data);
		envp = envp->next;
	}
	return (0);
}
