/*
** EPITECH PROJECT, 2017
** my_is_prime.c
** File description:
** know if number is prime
*/

#include "my.h"

int	my_is_prime(int nb)
{
	int i = 2;
	int x;

	switch (nb) {
		case 0 : return (0);
		case 1 : return (0);
		case 2 : return (1);
		case 3 : return (1);
	}
	while (i!= (nb + 1) / 2) {
		x = my_compute_power_rec(i, 2) + (i - 1);
		if (x == nb)
			return (1);
		x = my_compute_power_rec(i, 2) + (i + 1);
		if (x == nb)
			return (1);
		i++;
	}
	return (0);
}
