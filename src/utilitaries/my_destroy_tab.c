/*
** EPITECH PROJECT, 2017
** my_destroy_tab
** File description:
** my_destroy_tab
*/

#include "my.h"

void	my_destroy_tab(char **tab)
{
	if (tab == NULL)
		return;
	for (unsigned int i = 0; tab[i] != NULL; i++)
		free(tab[i]);
	free(tab);
}
