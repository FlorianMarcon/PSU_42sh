/*
** EPITECH PROJECT, 2017
** set_local
** File description:
** set_local
*/

#include <string.h>
#include "header_shell.h"
#include "variable.h"

void	create_variable_local(shell_t *shell, char **cmd, unsigned int *i)
{
	char *name = NULL;
	char *data = NULL;
	variable_t *var;

	if (cmd[*i] == NULL || cmd[*i][0] < 'A'|| cmd[*i][0] > 'z')
		return;
	name = my_strdup(cmd[*i]);
	if (cmd[*i + 1] != NULL && strcmp(cmd[*i + 1], "=") == 0) {
		data = strdup(cmd[*i + 2]);
		*i = *i + 2;
	}
	if (shell->list_local == NULL && (var = create_variable(name, data))
									!= NULL)
		shell->list_local = create_list(var);
	else if (shell->list_local != NULL)
		add_data_in_list(name, data, shell->list_local);
}

int	set_local(shell_t *shell, char **cmd)
{
	if (shell == NULL || cmd == NULL)
		return (1);
	for (unsigned int i = 1; i <= (unsigned int)len_tab(cmd); i++) {
		create_variable_local(shell, cmd, &i);
	}
	return (0);
}
