/*
** EPITECH PROJECT, 2017
** parsing_change_alias
** File description:
** parsing_change_alias
*/

#include "variable.h"
#include "header_shell.h"

char	**parsing_change_alias(linked_list_t *list, char **cmd)
{
	variable_t *var = NULL;
	char **tab;
	char **new;

	if (cmd[0] == NULL)
		return (cmd);
	var = search_variable(cmd[0], list);
	if (var == NULL || var->data == NULL)
		return (cmd);
	tab = parsing_str(var->data, ' ' | '\t');
	new = my_tabcat(tab, &cmd[1]);
	my_destroy_tab(tab);
	my_destroy_tab(cmd);
	return (new);
}
