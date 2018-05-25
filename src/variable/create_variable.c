/*
** EPITECH PROJECT, 2017
** create_variable
** File description:
** create_variable
*/

#include <stdlib.h>
#include <string.h>
#include "variable.h"

variable_t	*create_variable(char *name, void *data)
{
	variable_t *variable;

	if (name == NULL)
		return (NULL);
	if ((variable = malloc(sizeof(*variable))) == NULL)
		return (NULL);
	variable->name = name;
	if (variable->name == NULL) {
		free(variable);;
		return (NULL);
	}
	variable->data = data;
	return (variable);
}
