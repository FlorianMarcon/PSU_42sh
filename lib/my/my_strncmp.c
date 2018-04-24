/*
** EPITECH PROJECT, 2017
** my_strncmp.c
** File description:
** compare n first charactere to string
*/

#include "my.h"

int	my_strncmp(char const *s1, char const *s2, int n)
{
	int i = 0;

	for (; (s1[i] != '\0' || s2[i] != '\0') && i != n; i++) {
		if (s1[i] - s2[i] != 0)
			return (s1[i] - s2[i]);
	}
	return (0);
}
