/*
** EPITECH PROJECT, 2017
** add_data_in_list
** File description:
** add_data_in_list
*/

#include "variable.h"

void	add_data_in_list(char *name, void *data, linked_list_t *list)
{
	variable_t *var;

	if (name == NULL || list == NULL)
		return;
	var = search_variable(name, list);
	if (var != NULL) {
		if (var->data != NULL)
			free(var->data);
		var->data = data;
	} else {
		var = create_variable(name, data);
		create_node(list, var);
	}
}
