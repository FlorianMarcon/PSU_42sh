/*
** EPITECH PROJECT, 2017
** minishell2
** File description:
** create_linked_env
*/

#include <string.h>
#include "header_shell.h"
#include "variable.h"

variable_t	*create_variable_for_env(char *str)
{
	char *name = strtok(str, "=");
	char *data = strtok(NULL, "=");
	char *sub;
	variable_t *var = NULL;

	if (name == NULL)
		return (NULL);
	while ((sub = strtok(NULL, "=")) != NULL) {
		data = strcat(data, sub);
	}
	var = create_variable(name, data);
	return (var);
}
linked_list_t	*init_env(char **envp)
{
	linked_list_t *list = NULL;
	variable_t *var = NULL;

	if (envp == NULL)
		return (NULL);
	for (unsigned int i = 0; envp[i] != NULL; i++) {
		var = create_variable_for_env(envp[i]);
		if (var != NULL && list == NULL)
			list = create_list(var);
		else if (var != NULL)
			create_node(list, var);
	}
	return (list);
}
