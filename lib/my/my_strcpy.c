/*
** EPITECH PROJECT, 2017
** my_strcpy.c
** File description:
** copy string
*/

#include <unistd.h>
#include "my.h"

char	*my_strcpy(char *dest, char const *src)
{
	int i = 0;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
