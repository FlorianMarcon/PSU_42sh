/*
** EPITECH PROJECT, 2017
** create_variable
** File description:
** create_variable
*/

#include <stdlib.h>
#include <string.h>
#include "variable.h"

variable_t	*create_variable(char *name, char *data)
{
	variable_t *variable;

	if (name == NULL)
		return (NULL);
	if ((variable = malloc(sizeof(*variable))) == NULL)
		return (NULL);
	variable->name = strdup(name);
	if (variable->name == NULL) {
		free(variable);;
		return (NULL);
	}
	variable->data = NULL;
	if (data != NULL)
		variable->data = strdup(data);
	return (variable);
}
