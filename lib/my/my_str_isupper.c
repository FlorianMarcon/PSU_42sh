/*
** EPITECH PROJECT, 2017
** my_str_is_upper.c
** File description:
** know is str is uppercase
*/

#include <unistd.h>

int	my_str_isupper(char const *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] > 90 || str[i] < 65)
			return (0);
		else
			i++;
	}
	return (1);
}
