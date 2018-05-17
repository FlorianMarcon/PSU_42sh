/*
** EPITECH PROJECT, 2017
** search_variable
** File description:
** search_variable
*/

#include <string.h>
#include "variable.h"

variable_t	*search_variable(char *name, linked_list_t *list)
{
	variable_t *var;

	if (name == NULL)
		return (NULL);
	while (list != NULL) {
		var = list->data;
		if (var != NULL && strcmp(var->name, name) == 0)
			return (var);
		list = list->next;
	}
	return (NULL);
}
