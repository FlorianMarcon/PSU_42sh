/*
** EPITECH PROJECT, 2017
** my_strlen.c
** File description:
** return len by string
*/

#include <unistd.h>

int	my_putchar(char c);

int	my_strlen(char const *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	while (*str != '\0') {
		str++;
		i++;
	}
	return (i);
}
