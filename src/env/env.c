/*
** EPITECH PROJECT, 2017
** minishell2
** File description:
** is_built_in
*/

#include "env.h"

void	env(env_t *envp)
{
	while (envp != NULL) {
		my_putstr(envp->data);
		my_putchar('\n');
		envp = envp->next;
	}
}
