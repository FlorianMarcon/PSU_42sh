/*
** EPITECH PROJECT, 2017
** get_next_line_custom
** File description:
** get_next_line_custom
*/

#ifndef GNL_CUSTOM_
#define GNL_CUSTOM_

#include <stdlib.h>
#include <termios.h>

char	*gnl_custom(void);

void	gnl_custom_set_terminal(struct termios *term);

typedef struct	gnl_builtin_s {
	char label;
	char	*(*ptr)(char *, unsigned int *);
}gnl_builtin_t;

char	*gnl_delete_char(char *str, unsigned int *index);

char      *gnl_special(char *str, unsigned int *index);

static const gnl_builtin_t gnl_builtin[3] = {
	{127, &gnl_delete_char},
	{27, &gnl_special},
	{0, NULL}
};

char	*gnl_arrow(char *str, unsigned int *index);

static const gnl_builtin_t gnl_special_builtin[2] = {
	{91, &gnl_arrow},
	{0, NULL}
};
#endif
