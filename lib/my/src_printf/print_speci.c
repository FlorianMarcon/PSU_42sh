/*
** EPITECH PROJECT, 2017
** myprintf
** File description:
** printf
*/

#include "my.h"
#include "my_printf.h"

int	speci_print_int(char *str, int nb)
{
	int var = 0;
	int speci = find_speci(str);

	switch (speci) {
		case 0:
			var = speci_print_int_zero(str, nb);
			break;
		case 1:
			var = speci_print_int_one(nb);
			break;
		case 2:
			var = speci_print_int_two(str);
			break;
		case 4:
			var = speci_print_int_four(str, nb);
			break;
		}
		return (var);
}

int	speci_print_oct(char *str, char *string)
{
	int speci = find_speci(str);
	int var = 0;

	switch (speci) {
		case 0:	var = print_oct_speci_zero(str, string);
			break;
		case 1:	var = print_oct_speci_one(string);
			break;
		case 2:	var = print_oct_speci_two(str, string);
			break;
		case 3:	my_putchar('0');
			var = 1;
			break;
		case 4:	print_oct_speci_four(str, string);
			break;
		}
		return (var);
}

int	speci_print_hexa(char *str, char *string)
{
	int speci = find_speci(str);
	int var = 0;

	switch (speci) {
		case 0:	var = print_hexa_speci_zero(str, string);
			break;
		case 1:	var = print_hexa_speci_one(string);
			break;
		case 2:	var = print_hexa_speci_two(str, string);
			break;
		case 3:	my_putstr("0x");
			var = 1;
			break;
		case 4:	var = print_oct_speci_four(str, string);
			break;
		}
		return (var);
}

int	speci_print_hexa_maj(char *str, char *string)
{
	int speci = find_speci(str);
	int var = 0;

	switch (speci) {
		case 0:	var = print_hexa_speci_zero(str, string);
			break;
		case 1:	var = print_hexa_speci_one(string);
			break;
		case 2:	var = print_hexa_speci_two(str, string);
			break;
		case 3:	my_putstr("0X");
			var = 1;
			break;
		case 4:	var = print_oct_speci_four(str, string);
			break;
		}
		return (var);
}

int	speci_print_unint(char *str, unsigned int nb)
{
	int var = 0;
	int speci = find_speci(str);

	switch (speci) {
		case 0:
			var = print_unint_speci_zero(str, nb);
			break;
		case 4:
			var = print_unint_speci_four(str, nb);
			break;
		}
		return (var);
}
