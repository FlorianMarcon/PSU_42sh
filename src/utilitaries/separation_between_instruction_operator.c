/*
** EPITECH PROJECT, 2017
** separation_between_instruction_operator
** File description:
** separation_between_instruction_operator
*/

#include "header_shell.h"

char	*new_str(char *str, int i, char *op)
{
	char *new;
	char *tmp;

	for (int a = 0; a < my_strlen(op) && str[i] != '\0'; a++)
		str[i++] = '\0';
	new = my_strcat(str, " ");
	tmp = new;
	new = my_strcat(new, op);
	free(tmp);
	tmp = new;
	new = my_strcat(new, " ");
	free(tmp);
	tmp = new;
	new = my_strcat(new, &str[i]);
	free(tmp);
	free(str);
	return (new);
}

char	*operator_is_present(char *str)
{
	int a = 0;
	const char *operator[8]  = {
		";",
		"|",
		"&",
		">>",
		">",
		"<<",
		"<",
		NULL
	};

	if (str == NULL)
		return (NULL);
	while (operator[a] != NULL) {
		if (my_strncmp(operator[a], str, my_strlen(operator[a])) == 0)
			return (my_strdup(operator[a]));
		a++;
	}
	return (NULL);
}

char	*separation_between_instruction_operator(char *str)
{
	char *op;

	for (unsigned int i = 0; str != NULL && str[i] != '\0'; i++) {
		if ((op = operator_is_present(&str[i])) != NULL) {
			str = new_str(str, i, op);
			i = i + 1 + my_strlen(op);
			free(op);
		}
	}
	return (str);
}
