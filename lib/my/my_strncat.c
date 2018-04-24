/*
** EPITECH PROJECT, 2017
** my_strncat.c
** File description:
** i don't know
*/

#include <string.h>

int	my_strlen(char const *str);

char	*my_strncat(char *dest, char const *src, int nb)
{
	int n;
	int i = 0;

	n = my_strlen(dest);
	while (i != nb) {
		dest[n + i] = src[i];
		i++;
	}
	dest[n + i] = '\0';
	return (dest);
}
