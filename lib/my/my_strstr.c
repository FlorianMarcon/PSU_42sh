/*
** EPITECH PROJECT, 2017
** my_strstr.c
** File description:
** strstr
*/

#include <unistd.h>
#include "my.h"

char	*my_strstr(char const *s1, char const *s2)
{
	int i = 0;
	int a = 0;
	char *final;

	while (s1[i] != '\0') {
		while (s1[i] == s2[a] && s2[a] != '\0') {
			i++;
			a++;
		}
		if (a == 0)
			i++;
		if (s2[a] == '\0') {
			final = (char *)s1 + (i - a);
			return (final);
		}
		else
			a = 0;
	}
	return (NULL);
}
