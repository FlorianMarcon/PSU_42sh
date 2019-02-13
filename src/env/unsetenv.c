/*
** EPITECH PROJECT, 2017
** minishell1
** File description:
** unsetenv
*/

#include "header_shell.h"

void	delete(linked_list_t **list, char *cmd)
{
	linked_list_t *tmp = *list;
	linked_list_t *node = *list;
	variable_t *var = search_variable(cmd, tmp);

	if (tmp == NULL || var == NULL)
		return;
	if (tmp->data == var) {
		destroy_variable(var);
		*list = tmp->next;
		free(node);
	} else {
		while (tmp != NULL && tmp->next != NULL) {
			node = tmp->next;
			if (node->data == var) {
				destroy_variable(var);
				tmp->next = tmp->next->next;
				free(node);
			}
			tmp = tmp->next;
		}
	}
}

int	unset_env(shell_t *shell, char **cmd)
{
	int i = 0;


	if (cmd[1] == NULL)
		return (1);
	while (cmd[++i] != NULL)
		delete(&shell->list_env, cmd[i]);
	return (0);
}
