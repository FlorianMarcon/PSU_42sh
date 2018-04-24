/*
** EPITECH PROJECT, 2017
** myprintf
** File description:
** printf
*/

#include "my.h"
#include "my_printf.h"

int	speci_print_int_zero(char *str, int nb)
{
	int var = 0;
	int var2 = 0;

	var = my_getnbr(str);
	var2 = lenint(nb) - var;
	var = lenint(var) + 1;
	while (var2 < 0) {
		my_putchar('0');
		var2++;
	}
	return (var);
}

int	speci_print_int_one(int nb)
{
	int var = 1;

	if (nb >= 0)
		my_putchar('+');
	return (var);
}

int	speci_print_int_two(char *str)
{
	int var = 0;

	var = my_getnbr(str);
	if (var == 0)
		my_putchar(' ');
	while (var != 0) {
		my_putchar(' ');
		var--;
	}
	var = lenint(my_getnbr(str)) + 1;
	return (var);
}

int	speci_print_int_four(char *str, int nb)
{
	int var = 0;
	int var2 = 0;

	var = my_getnbr(str);
	var2 = lenint(nb) - var;
	if (str[0] >= '0' && str[0] <= '9')
		var = lenint(var);
	else
		var = 0;
	while (var2 < 0) {
		my_putchar(' ');
		var2++;
	}
	return (var);
}
