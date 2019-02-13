/*
** EPITECH PROJECT, 2017
** my_revstr.c
** File description:
** reverse string
*/

#include <unistd.h>

char	my_putchar(char c);

int	my_putstr(char const *str);

int	my_strlen(char const *str);

char	*my_revstr(char *str)
{
	char variable;
	int a_start;
	int a;

	a = my_strlen(str);
	a_start = a;
	a--;
	for (int i = 0; i != a_start / 2; i++) {
		variable = str[i];
		str[i] = str[a];
		str[a] = variable;
		a--;
	}
	return (str);
}
