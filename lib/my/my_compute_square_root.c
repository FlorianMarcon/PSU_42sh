/*
** EPITECH PROJECT, 2017
** my_compute_square_root.c
** File description:
** racine carré
*/

#include "my.h"

int	my_compute_square_root(int nb)
{
	int i = 0;

	while (i * i != nb) {
		i++;
		if (i > (nb))
			return (0);
	}
	return (i);
}
