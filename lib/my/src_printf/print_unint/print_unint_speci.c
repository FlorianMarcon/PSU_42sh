/*
** EPITECH PROJECT, 2017
** myprintf
** File description:
** printf
*/

#include "my.h"

int	print_unint_speci_zero(char *str, int nb)
{
	int var = my_getnbr(str);
	int var2 = len_unint(nb) - var;

	var = lenint(var);
	while (var2 < 0) {
		my_putchar('0');
		var2++;
	}
	return (var);
}

int	print_unint_speci_four(char *str, int nb)
{
	int var = my_getnbr(str);
	int var2 = len_unint(nb) - var;

	if (str[0] >= '0' && str[0] <= '9')
		var = lenint(var) -1;
	else
		var = -1;
	while (var2 < 0) {
		my_putchar(' ');
		var2++;
	}
	return (var);
}
