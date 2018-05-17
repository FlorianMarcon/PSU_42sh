/*
** EPITECH PROJECT, 2017
** env
** File description:
** env
*/

#include "hash_map.h"
#include "header_shell.h"
#include "variable.h"

int	env(shell_t *shell, char **cmd)
{
	linked_list_t *list = shell->list_env;
	variable_t *var;

	if (cmd[1] != NULL) {
		my_printf("env: «%s»: Aucun fichier ou dossier de ce type",
									cmd[1]);
		return (1);
	}
	while (list != NULL) {
		var = (variable_t *)list->data;
		if (var != NULL) {
			my_printf("%s=", var->name);
			if (var->data != NULL)
				my_printf("%s", var->data);
			my_printf("\n");
		}
		list = list->next;
	}
	return (0);
}
