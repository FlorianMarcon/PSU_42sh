/*
** EPITECH PROJECT, 2017
** len_unnit
** File description:
** obternir la taille d'un unsigned int
*/

#include "my.h"

int	len_unint(unsigned int nb)
{
	int size = 1;

	nb = nb / 10;
	if (nb != 0)
		size +=len_unint(nb);
	return (size);
}
