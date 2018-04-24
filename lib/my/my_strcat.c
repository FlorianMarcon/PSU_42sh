/*
** EPITECH PROJECT, 2017
** my_strcat.c
** File description:
** i don't know
*/

#include <string.h>
#include <stdlib.h>

int	my_strlen(char const *str);

char	*my_strcat(char *dest, char const *src)
{
	int len = my_strlen(dest) + my_strlen(src) + 1;
	char *resultat = NULL;
	int i = 0;

	if ((resultat = malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	len = 0;
	while (dest != NULL && dest[len] != '\0') {
		resultat[len] = dest[len];
		len++;
	}
	while (src != NULL && src[i] != '\0') {
		resultat[len] = src[i];
		len++;
		i++;
	}
	resultat[len] = '\0';
	return (resultat);
}
