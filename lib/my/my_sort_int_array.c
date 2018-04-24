/*
** EPITECH PROJECT, 2017
** my_sort_int_array.c
** File description:
** sort int in array
*/

#include "my.h"

void	my_sort_int_array(int *array, int size)
{
	int i = 0;
	int a = 1;
	int z = 0;
	int buff;

	while (z != size - 1) {
		i = z;
		a = i + 1;
		while (a != size) {
			if (array[i] > array[a]) {
				buff = array[i];
				array[i] = array[a];
				array[a] = buff;
				i = z;
				a = i + 1;
			}
			a++;
		}
		z++;
	}
}
