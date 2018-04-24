/*
** EPITECH PROJECT, 2017
** convert base
** File description:
** Test
*/

#include "my.h"
#include <stdlib.h>
char	*base_10(char const *nbr, int base);
int	how_chiffre(int nb);
int	chiffre(char const nbr);

void 	conv_base_to_second(char **buff, int var, int i, char **bss)
{
	char *buffer = *buff;
	char *bs = *bss;

	buffer[i] = var;
	bs = my_strdup(buffer);
	i++;
	buffer = malloc(sizeof(char) * (i + 2));
	my_strncpy(buffer, bs, i);
	*buff = buffer;
	*bss = bs;
}

char	*conv_base_to(char const *bs10, int base)
{
	int nb = my_getnbr(bs10);
	int var;
	int i = 0;
	char *bs;
	char *buffer = malloc(sizeof(char) * 2);

	while (nb != 0) {
		var = nb % base;
		nb = (nb - var) / base;
		if (var < 9)
			var += 48;
		else
			var += 55;
		conv_base_to_second(&buffer, var, i, &bs);
	}
	bs[i] = '\0';
	my_revstr(bs);
	return (bs);
}
