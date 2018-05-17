/*
** EPITECH PROJECT, 2017
** minishell1
** File description:
** unsetenv
*/

#include "env.h"

void	delete(linked_list_t *list, char **cmd)
{
	linked_list_t *to_unset;

	while (shell->env->next != NULL) {
		if (my_strncmp(shell->env->next->data, cmd[1],
					my_strlen(cmd[1])) == 0) {
			to_unset = shell->env->next;
			shell->env->next = shell->env->next->next;
			return;
		}
		shell->env = shell->env->next;
	}
	free (to_unset);
}

void	unset_env(shell_t *shell, char **cmd)
{

	if (cmd[1] == NULL)
		return;
	delete(shell->list_env, cmd);
}
