/*
** EPITECH PROJECT, 2017
** minishell1
** File description:
** unsetenv
*/

#include "env.h"

void	unset_env(char **cmd, env_t *env)
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
}
