/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** get_old_pwd
*/

#include "header_shell.h"

char	*get_old_pwd(env_t *env)
{
	while (env != NULL) {
		if (my_strncmp("OLDPWD=", env->data, 7) == 0)
			return (env->data);
		env = env->next;
	}
	return (NULL);
}
