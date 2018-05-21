/*
** EPITECH PROJECT, 2017
** my_char_ispresent
** File description:
** my_char_ispresent
*/

#include <stdlib.h>

int	my_char_ispresent(char *str, char label)
{
	if (str == NULL)
		return (0);
	for (unsigned int i = 0; str[i] != '\0'; i++)
		if (str[i] == label)
			return (1);
	return (0);
}
