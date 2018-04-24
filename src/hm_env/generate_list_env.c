/*
** EPITECH PROJECT, 2017
** generate_list_env
** File description:
** generate_list_env
*/

#include "my.h"
#include "environment.h"

variable_t	*create_variable(char **tab)
{
	variable_t *var;

	if (tab == NULL || len_tab(tab) != 2)
		return (NULL);
	if ((var = malloc(sizeof(*var))) == NULL)
		return (NULL);
	var->name = my_strdup(tab[0]);
	var->data = my_strdup(tab[1]);
	return (var);
}
linked_list_t	*generate_list_env(char **envp)
{
	char **tab;
	linked_list_t *list = NULL;
	variable_t *var;

	for (unsigned int i = 0; envp[i] != NULL; i++) {
		tab = parsing_str(envp[i], '=');
		var = create_variable(tab);
		if (var != NULL) {
			if (list == NULL)
				list = create_list(create_variable(tab));
			else
				create_node(list, create_variable(tab));
		}
		free(tab);
	}
	return (list);
}
