/*
** EPITECH PROJECT, 2017
** convert base
** File description:
** Test
*/

#include "my.h"
#include <stdlib.h>

int	chiffre(char const nbr);
int	how_chiffre(int nb);
char	*base_10(char const *nbr, int base);
char	*conv_base_to(char const *bs10, int base);

int	chiffre(char const nbr)
{
	int i = 48;
	int resul = 0;

	while (i != nbr) {
		i++;
		resul++;
		if (i == 58)
			i = 65;
	}
	return (resul);
}

int	how_chiffre(int nb)
{
	int i = 0;
	while (nb != 0) {
		nb = (nb - (nb % 10)) / 10;
		i++;
	}
	return (i);
}

char	*base_10(char const *nbr, int base)
{
	int a = my_strlen(nbr) - 1;
	int total = 0;
	int i = 0;
	char *final;

	while (a >= 0) {
		total = total + (chiffre(nbr[i])
		* (my_compute_power_rec(base, a)));
		a--;
		i++;
	}
	i = how_chiffre(total);
	final = malloc(sizeof(char) * (i + 1));
	i--;
	for (--i; i >= 0; i--) {
		final[i] = (total % 10) + 48;
		total = (total - (total % 10)) /10;
	}
	final[i] = '\0';
	return (final);
}

char	*convert_base(char const *nbr, char const *base_fr, char const *base_to)
{
	int lg_bs_fr = my_strlen(base_fr);
	int lg_bs_to = my_strlen(base_to);
	char *bs10;
	char *final;

	bs10 = (char *)nbr;
	if (lg_bs_fr != 10)
		bs10 = base_10(nbr, lg_bs_fr);

	if (lg_bs_to == 10)
		return (bs10);
	final = conv_base_to(bs10, lg_bs_to);
	return (final);
}
