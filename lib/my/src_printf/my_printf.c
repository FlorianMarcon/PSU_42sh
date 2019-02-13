/*
** EPITECH PROJECT, 2017
** myprintf
** File description:
** printf
*/

#include "my.h"
#include <stdarg.h>
#include <stdio.h>
#include "my_printf.h"

int	my_printf(char *str, ...)
{
	va_list tmp;
	int i = 0;
	int size = my_strlen(str);

	va_start(tmp, str);
	while (i < size) {
		if (str[i] == '%') {
			i++;
			i += choice_function(tmp, &str[i]);
		}
		else {
			my_putchar(str[i]);
			i++;
		}
	}
	va_end(tmp);
	return (0);
}
