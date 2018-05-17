/*
** EPITECH PROJECT, 2017
** setenv
** File description:
** setenv
*/

#include "hash_map.h"
#include "my.h"
#include "header_shell.h"
#include "variable.h"

int	set_env(shell_t *shell, char **cmd)
{
	variable_t *var;

	if (len_tab(cmd) > 3) {
		my_printf("setenv: Too many arguments.\n");
		return (1);
	}
	if (len_tab(cmd) == 1) {
		env(shell, cmd);
		return (0);
	}
	if ((var = malloc(sizeof(*var))) == NULL)
		return (1);
	var->name = my_strdup(cmd[1]);
	var->data = my_strdup(cmd[2]);
	if (shell->list_env == NULL)
		shell->list_env = create_list(var);
	else
		create_node(shell->list_env, var);
	hm_add_object(shell->env, var->name, var->data);
	return (0);
}
