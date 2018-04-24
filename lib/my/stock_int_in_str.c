/*
** EPITECH PROJECT, 2017
** stock_int_in_str
** File description:
** stock_int_in_str
*/

#include "my.h"
#include <stdlib.h>

char	*stock_int_in_str(int nb)
{
	int i = lenint(nb);
	char *str = malloc(sizeof(char) * (lenint(nb)));

	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	i--;
	while (nb != 0) {
		str[i] = (nb % 10) + '0';
		nb = (nb - (nb % 10)) / 10;
		i--;
	}
	return (str);
}
