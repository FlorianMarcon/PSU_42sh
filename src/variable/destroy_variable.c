/*
** EPITECH PROJECT, 2017
** destroy_variable
** File description:
** destroy_variable
*/

#include "variable.h"

void	destroy_variable(variable_t *var)
{
	if (var == NULL)
		return;
	if (var->name != NULL)
		free(var->name);
	if (var->data != NULL)
		free(var->data);
	free(var);
}
