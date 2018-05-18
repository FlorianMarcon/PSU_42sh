/*
** EPITECH PROJECT, 2017
** minishell1
** File description:
** setenv
*/

#include "header_shell.h"

char	*change_env(char **cmd, char *envp)
{
	char *new = "\0";

	new = my_strcat(new, cmd[1]);
	new = my_strcat(new, "=");
	new = my_strcat(new, cmd[2]);
	free (envp);
	return (new);
}

int	create_env(char **cmd, linked_list_t *env)
{
	char *new = "\0";

	new = my_strcat(new, cmd[1]);
	new = my_strcat(new, "=");
	new = my_strcat(new, cmd[2]);
	if (new == NULL)
		return (0);
	create_node_env(env, new);
	return (1);
}

int	mod_env(char **cmd, linked_list_t *env)
{
	while (env != NULL) {
		if (my_strncmp((char *)env->data, cmd[1], my_strlen(cmd[1])) == 0) {
			env->data = change_env(cmd, (char *)env->data);
			return (1);
		}
		env = env->next;
	}
	return (0);
}

void	set_env(shell_t *shell, char **cmd)
{
	if (cmd[1] == NULL)
		return;
	if (mod_env(cmd, shell->list_env) == 0)
		create_env(cmd, shell->list_env);
}
