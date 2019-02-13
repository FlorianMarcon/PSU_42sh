/*
** EPITECH PROJECT, 2017
** myprintf
** File description:
** printf
*/

#include "my.h"
#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"

int	find_speci(char *str)
{
	int z = 0;

	while (str[0] != tab_speci[z].balise && z < 4) {
		z++;
	}
	return (z);
}
