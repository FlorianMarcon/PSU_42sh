/*
** EPITECH PROJECT, 2017
** bistro
** File description:
** size int
*/

#include "my.h"

int	lenint(int nb)
{
	int size = 0;

	while (nb != 0) {
		nb -= (nb % 10);
		nb = nb / 10;
		size++;
	}
	return (size);
}
