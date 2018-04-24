/*
** EPITECH PROJECT, 2017
** my_tabdup
** File description:
** my_tabdup
*/

#include "my.h"

char	**my_tabdup(char **tab)
{
	char **new;
	int i = 0;

	if (tab == NULL)
		return (NULL);
	if ((new = malloc(sizeof(*new) * (len_tab(tab) + 1))) == NULL)
		return (NULL);
	while (tab[i] != NULL) {
		new[i] = my_strdup(tab[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}
