/*
** EPITECH PROJECT, 2017
** my_tabcat
** File description:
** my_tabcat
*/

#include <string.h>
#include "my.h"

char	**my_tabcat(char **fir, char **sec)
{
	char **new;
	unsigned int i = 0;

	if (fir == NULL || sec == NULL)
		return (NULL);
	if ((new = malloc(sizeof(*new) * (len_tab(fir) + len_tab(sec) + 1))) == NULL)
		return (NULL);
	for (unsigned int a = 0; fir[a] != NULL; a++)
		new[i++] = strdup(fir[a]);
	for (unsigned int a = 0; sec[a] != NULL; a++)
		new[i++] = strdup(sec[a]);
	new[i] = NULL;
	return (new);
}
