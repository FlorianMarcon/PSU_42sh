/*
** EPITECH PROJECT, 2017
** get_next_line
** File description:
** get_next_line
*/

#include <stdlib.h>

#ifndef READ_SIZE
#define READ_SIZE	5
#endif

#ifndef NEXT_LINE_
#define NEXT_LINE_

int	my_putstr(char const *str);

void	my_putchar(char c);

int	is_end_line(char *str);

char	*my_strcat(char *dest, char const *src);

int	my_strlen(char const *str);

char	*get_next_line(int fd);

char	*copy_extra_char(char *str);

#endif
