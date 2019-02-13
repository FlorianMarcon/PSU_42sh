/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** get_old_pwd
*/

#include "header_shell.h"

char	*get_old_pwd(linked_list_t *env)
{
	while (env != NULL) {
		if (my_strcmp("OLDPWD", ((variable_t *)env->data)->name) == 0)
			return (((variable_t *)env->data)->data);
		env = env->next;
	}
	return (NULL);
}
