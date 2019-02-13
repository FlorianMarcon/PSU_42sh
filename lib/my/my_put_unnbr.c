/*
** EPITECH PROJECT, 2017
** my_put_unnbr.c
** File description:
** display  unsigned number
*/

#include "my.h"

void	my_put_unnbr(unsigned int nb)
{
	int mod;

	mod = nb % 10;
	nb = nb / 10;
	if (nb != 0) {
		my_put_unnbr(nb);
		my_putchar(mod + '0');
	}
	else
		my_putchar(mod + '0');
}
