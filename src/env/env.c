/*
** EPITECH PROJECT, 2017
** minishell2
** File description:
** is_built_in
*/

#include "header_shell.h"

int	print_it(variable_t *var)
{
	if (var->name == NULL)
		return (84);
	my_printf("%s=", var->name);
	if (var->data == NULL)
		return (84);
	my_printf("%s\n", var->data);
}
int	env(shell_t *shell, char **cmd)
{
	linked_list_t *envp = shell->list_env;
	if (envp == NULL)
		return (84);
	while (envp != NULL) {
		print_it((variable_t *)envp->data);;
		envp = envp->next;
	}
	return (0);
}
