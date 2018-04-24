/*
** EPITECH PROJECT, 2017
** my_strdup.c
** File description:
** i don't know
*/

#include <stdlib.h>

int	my_strlen(char const *str);

char	*my_strdup(char const *str)
{
	char *arr;
	int n;
	int i = 0;

	n = my_strlen(str);
	arr = malloc(sizeof(char) * (n + 1));
	while (i != n) {
		arr[i] = str[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
