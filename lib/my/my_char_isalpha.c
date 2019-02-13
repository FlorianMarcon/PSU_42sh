/*
** EPITECH PROJECT, 2017
** my_char_isalpha.c
** File description:
** savoir si un char est une lettre
*/

#include "my.h"

int	my_char_isalpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
