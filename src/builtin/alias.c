/*
** EPITECH PROJECT, 2017
** alias
** File description:
** alias
*/

#include <string.h>
#include <stdlib.h>
#include "header_shell.h"

linked_list_t	*add_alias_in_list(linked_list_t *list, char **cmd)
{
	char *data = strdup(cmd[2]);
	variable_t *var = NULL;

	for (unsigned int i = 3; cmd[i] != NULL; i++) {
		data = strcat(data, " ");
		data = strcat(data, cmd[i]);
	}
	if (data == NULL)
		return (list);
	var = search_variable(cmd[1], list);
	if (var == NULL) {
		var = create_variable(cmd[1], data);
		if (list == NULL)
			list = create_list(var);
		else
			create_node(list, var);
	} else {
		free(var->data);
		var->data = strdup(data);
	}
	free(data);
	return (list);
}
int	alias(shell_t *shell, char **cmd)
{
	(void)shell;
	if (len_tab(cmd) <= 1)
		return (1);
	if (len_tab(cmd) <= 2)
		return (0);
	shell->list_alias = add_alias_in_list(shell->list_alias, cmd);
	return (0);
}
