/*
** EPITECH PROJECT, 2017
** replace_variable
** File description:
** replace_variable
*/

#include <string.h>
#include "header_shell.h"
#include "variable.h"

variable_t	*search_variable_matching(char *str, linked_list_t *list)
{
	variable_t *var;

	while (list != NULL) {
		var = (variable_t *)list->data;
		if (var != NULL && strncmp(var->name, str, strlen(var->name))
									== 0)
			return (var);
		list = list->next;
	}
	return (NULL);
}
char	*replace_variable(char *str, int i, shell_t *shell)
{
	char *new = NULL;
	variable_t *var;

	str[i] = '\0';
	var = search_variable_matching(&str[i + 1], shell->list_local);
	if (var == NULL) {
		var = search_variable_matching(&str[i + 1], shell->list_env);
	}
	if (var == NULL) {
		fprintf(stderr, "%s: Undefined variable.\n", &str[i + 1]);
		return (NULL);
	}
	new = my_strdup(str);
	if (var->data != NULL) {
		new = my_strcat(new, var->data);
	}
	new = my_strcat(new, &str[i + strlen(var->name) + 1]);
	return (new);
}
char	*parsing_change_variable(char *str, shell_t *shell)
{
	char *tmp = str;

	for (int i = 0; str != NULL && str[i] != '\0'; i++) {
		if (str[i] == '$' && (i == 0 || str[i - 1] != '\\')) {
			tmp = str;
			str = replace_variable(str, i, shell);
			free(tmp);
			i = -1;
		}
	}
	return (str);
}
