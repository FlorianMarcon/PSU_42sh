/*
** EPITECH PROJECT, 2017
** myprintf
** File description:
** printf
*/

#include "my.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_printf.h"

int	choice_function_second(va_list tmp, char *str, int balise)
{
	int i = 0;
	int size;

	while (i != 12) {
		if (str[balise] == tab[i].balise) {
			size = tab[i].fptr(tmp, str);
			return (size);
		}
		i++;
	}
	return (0);
}

int	choice_function(va_list tmp, char *balise)
{
	int i = 0;
	int var;

	while ((var = choice_function_second(tmp, balise, i))\
						== 0) {
		i++;
	}
	return (i + 1);
}
