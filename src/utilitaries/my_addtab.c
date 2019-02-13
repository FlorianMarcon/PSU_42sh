/*
** EPITECH PROJECT, 2017
** my_addtab
** File description:
** my_addtab
*/

#include "my.h"

char	**my_addtab(char **tab, char *str)
{
	char **new;
	unsigned int i = 0;

	if (tab == NULL)
		return (NULL);
	if ((new = malloc(sizeof(*new) * (len_tab(tab) + 2))) == NULL)
		return (NULL);
	while (tab[i] != NULL) {
		new[i] = my_strdup(tab[i]);
		i++;
	}
	new[i++] = my_strdup(str);
	new[i] = NULL;
	return (new);
}
