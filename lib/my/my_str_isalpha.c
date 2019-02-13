/*
** EPITECH PROJECT, 2017
** my_str_isalpha.c
** File description:
** know if str is alpha
*/

#include <unistd.h>

int	my_str_isalpha(char const *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] < 65 || str[i] > 122)
			return (0);
		if (str[i] > 90 && str[i] < 97)
			return (0);
		else
			i++;
	}
	return (1);
}
