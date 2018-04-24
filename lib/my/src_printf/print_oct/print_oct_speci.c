/*
** EPITECH PROJECT, 2017
** myprintf
** File description:
** printf
*/

#include "my.h"
#include "my_printf.h"

int	print_oct_speci_zero(char *str, char *string)
{
	int var = 0;

	var = my_strlen(string) - my_getnbr(str);
	while (var < 0) {
		my_putchar('0');
		var++;
	}
	var = lenint(my_getnbr(str)) + 1;
	return (var);
}

int	print_oct_speci_one(char *string)
{
	int var = 1;

	if (my_getnbr(string) >= 0)
		my_putchar('+');
	return (var);
}

int	print_oct_speci_two(char *str, char *string)
{
	int var = 0;

	var = my_getnbr(str) - my_strlen(string);
	if (var == 0)
		var = 1;
	while (var >= 0) {
		my_putchar(' ');
		var--;
	}
	var = lenint(my_getnbr(str)) + 1;
	return (var);
}

int	print_oct_speci_four(char *str, char *string)
{
	int var = 0;

	var = my_strlen(string) - my_getnbr(str);
	while (var < 0) {
		my_putchar(' ');
		var++;
	}
	if (string[0] >= '0' && string[0] <= '9')
		var = lenint(my_getnbr(str));
	else
		var = 0;
	return (var);
}
