/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** get_env
*/

#include "header_shell.h"

char	**get_env(linked_list_t *env)
{
	char **new = malloc(sizeof(char *) * (len_list(env) + 1));
	int i = -1;

	while (env != NULL) {
		new[++i] = malloc(my_strlen(((variable_t *)env->data)->name) + 1);
		new[i] = my_strcpy(new[i], ((variable_t *)env->data)->name);
		new[i] = my_strcat(new[i], ((variable_t *)env->data)->data);
		env = env->next;
	}
	new[++i] = NULL;
	return (new);
}
