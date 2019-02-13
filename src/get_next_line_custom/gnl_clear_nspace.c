/*
** EPITECH PROJECT, 2017
** gnl_clear_nspace
** File description:
** gnl_clear_nspace
*/

#include <stdio.h>

void	gnl_clear_nspace(unsigned int size)
{
	for (unsigned int i = 0; i < size; i++) {
		dprintf(1, "\b \b");
	}
}
