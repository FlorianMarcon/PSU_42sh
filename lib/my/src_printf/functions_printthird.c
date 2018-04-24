/*
** EPITECH PROJECT, 2017
** myprintf
** File description:
** printf
*/

#include "my.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "my_printf.h"

int	print_unint(va_list tmp, char *str)
{
	unsigned int nb = va_arg(tmp, unsigned int);
	int len = speci_print_unint(str, nb);

	my_put_unnbr(nb);
	return (len);
}

int	print_adresse(va_list tmp, char *str)
{
	unsigned int unsi = va_arg(tmp, unsigned int);
	char *var2 = stock_int_in_str((int)unsi);
	int speci = find_speci(str);

	if (speci == 4) {
		var2 = convert_baseten_to_n\
					(my_getnbr(var2),"0123456789ABCDEF");
		my_putstr("0x");
		my_putstr(var2);
	}
	else
		my_putstr("\nDON'T NEED TO PRECISION: ONLY %%p\n");
	return (1);
}
