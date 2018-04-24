/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** header my _printf
*/

#include <stdarg.h>
#include <stdio.h>

#ifndef MY_PRINTF_
#define MY_PRINTF_

int	my_printf(char *str, ...);

typedef struct tab {
	char balise;
	int (*fptr)(va_list, char *);
} tab_t;

typedef struct specifier {
	char balise;
	int size;
} specifier_t;

int	choice_function(va_list tmp, char *balise);

int	find_speci(char *str);

void	use_speci(int speci, void *data);

int	speci_print_int(char *str, int nb);

int	speci_print_int_zero(char *str, int nb);

int	speci_print_int_four(char *str, int nb);

int	speci_print_int_two(char *str);

int	speci_print_int_one(int nb);

int	speci_print_oct(char *str, char *string);

int	print_oct_speci_zero(char *str, char *string);

int	print_oct_speci_one(char *string);

int	print_oct_speci_two(char *str, char *string);

int	print_oct_speci_four(char *str, char *string);

int	speci_print_hexa(char *str, char *string);

int	print_hexa_speci_zero(char *str, char *string);

int	print_hexa_speci_one(char *string);

int	print_hexa_speci_two(char *str, char *string);

int	print_hexa_speci_four(char *str, char *string);

int	speci_print_hexa_maj(char *str, char *string);

int	speci_print_unint(char *str, unsigned int nb);

int	print_unint_speci_zero(char *str, int nb);

int	print_unint_speci_four(char *str, int nb);

int	print_s_octal(char c);

int	print_s(va_list tmp, char *str);

int	print_string(va_list tmp, char *str);

int	print_char(va_list tmp, char *str);

int	print_int(va_list tmp, char *str);

int	print_binary(va_list tmp, char *str);

int	print_oct(va_list tmp, char *str);

int	print_hexa(va_list tmp, char *str);

int	print_hexa_maj(va_list tmp, char *str);

int	print_unint(va_list tmp, char *str);

int	print_adresse(va_list tmp, char *str);

static tab_t const tab[13] = {{'c', print_char}, {'s', print_string},
				{'d', print_int}, {'i', print_int},
				{'b', print_binary}, {'o', print_oct},
				{'x', print_hexa}, {'X', print_hexa_maj},
				{'u', print_unint}, {'u', print_unint},
				{'p', print_adresse}, {'S', print_s},
				{'%', print_int}};

static specifier_t const tab_speci[4] = {{'.', 1}, {'+', 1},
					{' ', 1}, {'#', 1}};

#endif
