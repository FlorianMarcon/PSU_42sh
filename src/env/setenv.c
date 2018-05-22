/*
** EPITECH PROJECT, 2017
** minishell1
** File description:
** setenv
*/

#include "header_shell.h"

int	create_env(char **cmd, linked_list_t *env)
{
	variable_t *var = malloc(sizeof(*var) * 1);
	linked_list_t *new = malloc(sizeof(*new) * 1);

	if (var == NULL)
		return (1);
	var->name = cmd[1];
	var->data = cmd[2];
	new->data = var;
	new->next = NULL;
	while (env->next->next != NULL)
		env = env->next;
	add_node(env, new);
	return (0);
}

int	mod_env(char **cmd, linked_list_t *env)
{
	while (env != NULL) {
		if (my_strcmp(((variable_t *)env->data)->name, cmd[1]) == 0) {
			((variable_t *)env->data)->data = cmd[2];
			return (0);
		}
		env = env->next;
	}
	return (1);
}

int	set_env(shell_t *shell, char **cmd)
{
	if (cmd[1] == NULL)
		return (1);
	if (mod_env(cmd, shell->list_env) == 1)
		if (create_env(cmd, shell->list_env) == 1)
			return (1);
	return (0);
}
