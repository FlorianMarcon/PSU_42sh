/*
** EPITECH PROJECT, 2017
** generate_list_env
** File description:
** generate_list_env
*/

#include "my.h"
#include "variable.h"

linked_list_t	*generate_list_env(char **envp)
{
	char **tab;
	linked_list_t *list = NULL;
	variable_t *var;

	for (unsigned int i = 0; envp[i] != NULL; i++) {
		tab = parsing_str(envp[i], '=');
		var = create_variable(tab[0], tab[1]);
		if (var != NULL) {
			if (list == NULL)
				list = create_list(var);
			else
				create_node(list, var);
		}
		free(tab);
	}
	return (list);
}
