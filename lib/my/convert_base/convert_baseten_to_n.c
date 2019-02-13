/*
** EPITECH PROJECT, 2017
** convert_base
** File description:
** convert_base
*/

#include <stdlib.h>
#include <stdio.h>

int	my_strlen(char *str);

char	*my_revstr(char *str);

char	*convert_baseten_to_n(int nb, char *base_to)
{
	char *new = malloc(sizeof(char) * (nb + 1));
	int indice = 0;
	int var;
	int size_base = my_strlen(base_to);

	while (nb != 0) {
		var = nb % size_base;
		nb = nb / size_base;
		new[indice] = base_to[var];
		indice++;
	}
	new[indice] = '\0';
	new = my_revstr(new);
	return (new);
}
