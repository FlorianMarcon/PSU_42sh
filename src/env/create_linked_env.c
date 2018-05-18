/*
** EPITECH PROJECT, 2017
** minishell2
** File description:
** create_linked_env
*/

#include "header_shell.h"

char	*get_name(char *str)
{
	int i = -1;
	char *name;

	while (str[++i] != '=' && str[i] != '\0');
	if (str[i] == '=') {
		name = malloc(i + 1);
		i = -1;
		while (str[++i] != '=')
			name[i] = str[i];
		name[i] = '\0';
		return (name);
	}
	return (NULL);
}

int	up_i(char *str)
{
	int i = -1;
	while (str[++i] != '=' && str[i] != '\0');
	if (str[i] == '=')
		return (i);
	return (-1);
}

char	*get_data(char *str)
{
	int i = up_i(str);
	int j = -1;
	char *data;

	if (i == -1)
		return (NULL);
	data = malloc(my_strlen(str) - i);
	while (str[++i] != '\0')
		data[++j] = str[i];
	data[++j] = '\0';
	return (data);
}

variable_t	*create_var(char *str)
{
	variable_t *var = malloc(sizeof(*var) * 1);

	var->name = get_name(str);
	var->data = get_data(str);
	return (var);
}

linked_list_t	*init_env(char **envp)
{
	int i = 0;
	linked_list_t *env = malloc(sizeof(*env) * 1);

	if (env == NULL)
		return (NULL);
	env->data = create_var(envp[i]);
	env->next = NULL;
	while (envp[++i] != NULL)
		create_node(env, create_var(envp[i]));
	return (env);
}
