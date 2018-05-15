/*
** EPITECH PROJECT, 2017
** gnl_arrow
** File description:
** gnl_arrow
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "gnl_custom.h"

char	*gnl_arrow(char *str, unsigned int *index)
{
        char new[2] = " \0";

        if (read(0, new, 1) == -1)
	        return (str);
        switch (new[0]) {
                case 65: dprintf(1, "up");
                break;
                case 66: dprintf(1, "down");
                break;
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
        }
        return (str);
}
char	*gnl_special(char *str, unsigned int *index)
{
        char new[2] = " \0";

        if (read(0, new, 1) == -1)
        	return (str);
        for (unsigned int i = 0; gnl_special_builtin[i].label != 0; i++) {
                if (new[0] == gnl_special_builtin[i].label) {
                        str = gnl_special_builtin[i].ptr(str, index);
                        return (str);
                }
        }
        return (str);
}
