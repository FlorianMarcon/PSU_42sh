/*
** EPITECH PROJECT, 2017
** unset_local
** File description:
** unset_local
*/

#include "header_shell.h"
#include "variable.h"

void	destroy_local_variable(linked_list_t **list_local, variable_t *var)
{
	linked_list_t *list = *list_local;
	linked_list_t *tmp = *list_local;

	while (list != NULL && list->data != var)
		list = list->next;
	if (list == NULL)
		return;
	if (list == *list_local)
		*list_local = (*list_local)->next;
	else {
		while (tmp->next != list)
			tmp = tmp->next;
		tmp->next = tmp->next->next;
		}
	destroy_variable(var);
	free(list);
}
int	unset_local(shell_t *shell, char **cmd)
{
	variable_t *var;

	for (unsigned int i = 1; cmd[i] != NULL; i++) {
		var = search_variable(cmd[i], shell->list_local);
		if (var != NULL) {
			destroy_local_variable(&shell->list_local, var);
		}
	}
	return (0);
}
