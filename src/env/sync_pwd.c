/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** sync pwd
*/

#include "string.h"
#include "header_shell.h"

void	sync_value(linked_list_t *list, char *new, char *to_find)
{
	variable_t *var = list->data;

	while (my_strcmp(var->name, to_find) != 0) {
		list = list->next;
		var = list->data;
	}
	if (list != NULL) {
		var->data = new;
		list->data = var;
	}
}
void	sync_pwd(shell_t *shell)
{
	sync_value(shell->list_env, strdup(shell->old_pwd), "OLDPWD");
	sync_value(shell->list_env, strdup(shell->pwd), "PWD");
	//printf("%s\n", )
}
