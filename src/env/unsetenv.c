/*
** EPITECH PROJECT, 2017
** minishell1
** File description:
** unsetenv
*/

#include "header_shell.h"

void	delete(linked_list_t *list, char *cmd)
{
	while (my_strcmp(((variable_t *)list->next->data)->name, cmd) != 0
							&& list->next != NULL)
		list = list->next;
	if (list->next != NULL) {
		free(((variable_t *)list->next->data)->name);
		free(((variable_t *)list->next->data)->data);
		free(list->next->data);
		delete_node(list);
	}
}

int	unset_env(shell_t *shell, char **cmd)
{
	int i = 0;
	if (cmd[1] == NULL)
		return (1);
	while (cmd[++i] != NULL)
		delete(shell->list_env, cmd[i]);
	return (0);
}
