/*
** EPITECH PROJECT, 2017
** minishell1
** File description:
** unsetenv
*/

#include "header_shell.h"

/*void	unset_env(shell_t *shell, char **cmd)
{
	env_t *to_unset;

	if (cmd[1] == NULL)
		return;
	while (env->next != NULL) {
		if (my_strncmp(env->next->data, cmd[1],
						my_strlen(cmd[1])) == 0) {
			to_unset = env->next;
			env->next = env->next->next;
			return;
		}
		env = env->next;
	}
	free (to_unset);
}*/

void	unset_env(shell_t *shell, char **cmd)
{
	int i = 0;
	env_t *to_unset;
	env_t *fix = shell->env;

	if (cmd[1] == NULL)
		return;
	while (cmd[++i] != NULL) {
		while (my_strcmp(shell->env->next->name, cmd[i]) != 0 &&
						shell->env->next != NULL) {
			shell->env = shell->env->next;
		}
		if (shell->env->next != NULL) {
			to_unset = shell->env->next;
			shell->env->next = shell->env->next->next;
			free (to_unset);
		}
		shell->env = fix;
	}
}
