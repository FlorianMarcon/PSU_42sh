/*
** EPITECH PROJECT, 2017
** my_strcmp.c
** File description:
** compare two string
*/

#include "my.h"

int	my_strcmp(char const *s1, char const *s2)
{
	int i = 0;

	for (; s1[i] != '\0' || s2[i] != '\0'; i++) {
		if (s1[i] - s2[i] != 0)
			return (s1[i] - s2[i]);
	}
	return (0);
}
