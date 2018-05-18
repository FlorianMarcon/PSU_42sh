/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** set_pwd
*/

#include "header_shell.h"

void	create_oldpwd(shell_t *shell, char *old)
{
	env_t *old_pwd;

	old_pwd->name = "OLDPWD";
	old_pwd->data = old;
	old_pwd->next = NULL;
	while (shell->env->next != NULL)
		shell->env = shell->env->next;
	shell->env->next = old_pwd;
}

void	set_pwd(shell_t *shell)
{
	while (shell->env != NULL) {
		if (my_strcmp(shell->env->name , "PWD") == 0)
			shell->pwd = shell->env->data;
		if (my_strcmp(shell->env->name, "OLDPWD") == 0)
			shell->old_pwd = shell->env->data;
		shell->env = shell->env->next;
	}
}
