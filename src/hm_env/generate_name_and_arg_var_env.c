/*
** EPITECH PROJECT, 2017
** generate_var_env
** File description:
** generate_var_env
*/

#include "environment.h"
#include "my.h"

char	*generate_name_var_env(char *str)
{
	char *res;
	int i = 0;

	str = my_strdup(str);
	while (str[i] != '=') {
		if (str[i++] == '\0') {
			free(str);
			return (NULL);
		}
	}
	str[i] = '\0';
	res = my_strdup(str);
	free(str);
	return (res);
}

linked_list_t	*generate_arg_var_env(char *arg)
{
	linked_list_t *list = NULL;
	char **tab = parsing_str(arg, ':');

	if (tab == NULL)
		return (NULL);
	for (unsigned int i = 0; tab[i] != NULL; i++) {
		if (list == NULL)
			list = create_list(my_strdup(tab[i]));
		else
			create_node(list, tab[i]);
	}
	free(tab);
	return (list);
}
