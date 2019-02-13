/*
** EPITECH PROJECT, 2017
** is_operator
** File description:
** is_operator
*/

#include "my.h"
#include "header_shell.h"

int	is_operator(char *str)
{
	int a = 0;

	if (str == NULL)
		return (0);
	while (run_op[a].label != NULL)
		if (my_strcmp(run_op[a++].label, str) == 0)
			return (1);
	return (0);
}
