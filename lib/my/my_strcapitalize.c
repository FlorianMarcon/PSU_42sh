/*
** EPITECH PROJECT, 2017
** my_capitalize.c
** File description:
** put captalize
*/

#include "my.h"

char	*my_strcapitalize(char *str)
{
	int i = 0;

	str = my_strlowcase(str);
	while (str[i] != '\0') {
		if (my_char_isalpha(str[i]) == 1 &&
			my_char_isalpha(str[i - 1]) == 0 &&
			my_char_isnum(str[i - 1]) == 0)
			str[i] -= 32;
		i++;
	}
	return (str);
}
