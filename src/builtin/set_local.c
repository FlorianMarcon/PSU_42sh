/*
** EPITECH PROJECT, 2017
** set_local
** File description:
** set_local
*/

#include <string.h>
#include "header_shell.h"
#include "variable.h"

variable_t	*create_variable_local(char **cmd, unsigned int *i)
{
	variable_t *var;

	if (cmd[*i] == NULL || cmd[*i][0] < 'A'|| cmd[*i][0] > 'z')
		return (NULL);
	if ((var = malloc(sizeof(*var))) == NULL)
		return (NULL);
	var->name = strdup(cmd[*i]);
	var->data = NULL;
	if (cmd[*i + 1] != NULL && strcmp(cmd[*i + 1], "=") == 0) {
		var->data = strdup(cmd[*i + 2]);
		*i = *i + 2;
	}
	return (var);
}
void	add_variable_list_local(shell_t *shell, variable_t *var)
{
	variable_t *ocu = search_variable(var->name, shell->list_local);

	if (ocu != NULL) {
		if (ocu->data != NULL)
			free(ocu->data);
		ocu->data = my_strdup(var->data);
		destroy_variable(var);
	} else {
		if (shell->list_local == NULL)
			shell->list_local = create_list(var);
		else
			create_node(shell->list_local, var);
	}
}
int	set_local(shell_t *shell, char **cmd)
{
	variable_t *var;

	if (shell == NULL || cmd == NULL)
		return (1);
	for (unsigned int i = 1; i <= (unsigned int)len_tab(cmd); i++) {
		var = create_variable_local(cmd, &i);
		if (var != NULL) {
			add_variable_list_local(shell, var);
		}
	}
	return (0);
}
