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

int	print_binary(va_list tmp, char *str)
{
	unsigned int unsi = va_arg(tmp, unsigned int);
	char *string = stock_int_in_str(unsi);
	int speci = find_speci(str);

	if (speci == 4) {
		string = convert_baseten_to_n(my_getnbr(string), "01");
		my_putstr(string);
	}
	else
		my_putstr("\nDON'T NEED TO PRECISION: ONLY %%b\n");
	return (1);
}

int	print_oct(va_list tmp, char *str)
{
	int nb = va_arg(tmp, int);
	char *string = stock_int_in_str(nb);
	int len;

	string = convert_baseten_to_n\
			(my_getnbr(string), "01234567");
	len = speci_print_oct(str, string);
	my_putstr(string);
	return (len + 1);
}

int	print_hexa(va_list tmp, char *str)
{
	int nb = va_arg(tmp, int);
	char *string = stock_int_in_str(nb);
	int len = 0;

	string = convert_baseten_to_n\
		(my_getnbr(string), "0123456789abcdef");
	len += speci_print_hexa(str, string);
	string = my_strlowcase(string);
	my_putstr(string);
	return (len + 1);
}

int	print_hexa_maj(va_list tmp, char *str)
{
	int nb = va_arg(tmp, int);
	char *string = stock_int_in_str(nb);
	int len =  0;

	string = convert_baseten_to_n(my_getnbr(string), "0123456789ABCDEF");
	len += speci_print_hexa_maj(str, string);
	my_putstr(string);
	return (len + 1);
}

void	print_len(va_list tmp, int size)
{
	int *len = va_arg(tmp , int *);

	*len = size;
}
