/*
** EPITECH PROJECT, 2017
** my_compute_power_rec.c
** File description:
** puissance
*/

#include "my.h"

int	my_compute_power_rec(int nb, int p)
{
	if (p < 0)
		return (0);
	if (p == 0)
		return (1);
	if (p != 1) {
		p--;
		nb = nb * (my_compute_power_rec(nb, p));
	}
	return (nb);
}
