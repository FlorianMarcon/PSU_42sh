/*
** EPITECH PROJECT, 2017
** gnl_arrow
** File description:
** gnl_arrow
*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>

char	*gnl_arrow(char *str, unsigned int *index)
{
        char new[2] = " \0";

        if (read(0, new, 1) == -1)
	        return (str);
        switch (new[0]) {
                case 67: if (*index != strlen(str)) {
                        dprintf(1, "\033[1C");
                        *index = *index + 1;
                }
                	break;
                case 68: if (*index != 0) {
                        dprintf(1, "\033[1D");
                        *index = *index - 1;
                }
	                break;
                default: break;
        }
        return (str);
}
