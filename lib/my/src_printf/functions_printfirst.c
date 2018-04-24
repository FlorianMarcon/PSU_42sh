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

int	print_s_octal(char c)
{
	int size = 0;
	int i = 0;
	int var;
	char *var2;

	my_putchar('\\');
	var = c;
	var2 = stock_int_in_str(var);
	var2 = convert_baseten_to_n\
			(my_getnbr(var2), "01234567");
	size = my_strlen(var2);

	while (i + size != 3) {
		my_putchar('0');
		i++;
	}
	my_putstr(var2);
	return (size);
}

int	print_s(va_list tmp, char *str)
{
	char *string = va_arg(tmp, char *);
	int size = 0;
	int i = 0;
	int speci = find_speci(str);

	while (string[i] != '\0') {
		if (string[i] < 32 || string [i] >= 127) {
			size += print_s_octal(string[i]);
		}
		else{
			my_putchar(string[i]);
			size++;
		}
		i++;
	}
	if (speci != 4)
		my_putstr("\nDON'T NEED TO PRECISION: ONLY %%S\n");
	return (1);
}

int	print_string(va_list tmp, char *str)
{
	char *string = va_arg(tmp, char *);
	int speci = find_speci(str);
	int var = 0;
	int i = 0;

	if (speci == 4) {
		my_putstr(string);
	} else if (speci == 0) {
		var = my_getnbr(str);
		while (i < var && string[i] != '\0') {
			my_putchar(string[i]);
			i++;
		}
		var = lenint(my_getnbr(str)) + 1;
	} else
		my_putstr("\nDON'T NEED TO PRECISION: ONLY %%s\n");
	return (var + 1);
}

int	print_char(va_list tmp, char *str)
{
	int letter = va_arg(tmp, int);
	int speci = find_speci(str);

	if (speci == 4)
		my_putchar(letter);
	else
		my_putstr("\nDON'T NEED TO PRECISION: ONLY %%c\n");
	return (1);
}

int	print_int(va_list tmp, char *str)
{
	int nb = va_arg(tmp, int);
	int var = speci_print_int(str, nb);

	my_put_nbr(nb);
	return (1 + var);
}
