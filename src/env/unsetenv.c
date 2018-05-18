/*
** EPITECH PROJECT, 2017
** minishell1
** File description:
** unsetenv
*/

#include "header_shell.h"

void	delete(linked_list_t *list, char *cmd)
{
	while (my_strcmp(list->next->data->name, cmd) != 0 && list->next != NULL)
		list = list->next;
	if (list->next != NULL) {
		free(list->data->name);
		free(list->data->data);
		free(list->data);
		delete_node(list);
	}
}

void	unset_env(shell_t *shell, char **cmd)
{

	if (cmd[1] == NULL)
		return;
	while (cmd[++i] != NULL)
		delete(shell->list_env, cmd[i]);
}
