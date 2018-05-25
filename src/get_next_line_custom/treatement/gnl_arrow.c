/*
** EPITECH PROJECT, 2017
** gnl_arrow
** File description:
** gnl_arrow
*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "gnl_custom.h"

void	gnl_arrow_treatement(unsigned int *ind, shell_t *sh, int nb, char *str)
{
	int i = sh->index;

	switch (nb) {
		case 65: if (i != sh->size_history &&
						sh->history[i + 1] != NULL)
			sh->index++;
		break; if (i != -1)
			i--;
		case 66:
		break;
		case 67: if (*ind != strlen(str)) {
			dprintf(1, "\033[1C");
			*ind = *ind + 1;
		}
		break;
		case 68: if (*ind != 0) {
			dprintf(1, "\033[1D");
			*ind = *ind - 1;
		}
		break;
}

}
char	*gnl_arrow(char *str, unsigned int *index, shell_t *sh)
{
	char new[2] = " \0";

	if (read(0, new, 1) == -1)
		return (str);
	gnl_arrow_treatement(index, sh, new[0], str);
	return (str);
}
