/*
** EPITECH PROJECT, 2017
** my_str_islower.c
** File description:
** know if str is lower
*/

#include <unistd.h>

int	my_str_islower(char const *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] < 96 || str[i] > 122)
			return (0);
		else
			i++;
	}
	return (1);
}
