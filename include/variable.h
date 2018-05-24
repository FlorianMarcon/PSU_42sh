/*
** EPITECH PROJECT, 2017
** environnement
** File description:
** environnement
*/

#ifndef VARIABLE_
#define VARIABLE_

#include "my.h"
#include "hash_map.h"

typedef struct variable {
	char *name;
	char *data;
}variable_t;

// local variable

variable_t	*create_variable_local(char **cmd, unsigned int *i);

void	destroy_local_variable(linked_list_t **list_local, variable_t *var);

//utilitaries variable

variable_t	*search_variable(char *name, linked_list_t *list);

variable_t	*search_variable_matching(char *str, linked_list_t *list);

variable_t	*create_variable(char *name, char *data);

void	destroy_variable(variable_t *var);

#endif
