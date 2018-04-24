/*
** EPITECH PROJECT, 2017
** my_tabdup
** File description:
** my_tabdup
*/

#include "my.h"

char	**my_tabdup(char **tab)
{
	char **new = malloc(sizeof(*new) * (lentab(tab) + 1));

	if (new == NULL)
		return (NULL);
	return (new);
}
