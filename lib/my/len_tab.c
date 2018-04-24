/*
** EPITECH PROJECT, 2017
** len_tab
** File description:
** len_tab
*/

#include "my.h"

int	len_tab(char **tab)
{
	int i = 0;

	if (tab == NULL)
		return (-1);
	while (tab[i] != NULL)
		i++;
	return (i);
}
