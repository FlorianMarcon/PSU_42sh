/*
** EPITECH PROJECT, 2017
** my_swap.c
** File description:
** swap
*/

void	my_swap(int *a,int *b)
{
	int *c;
	int *e;
	int d;
	int f;

	c = &d;
	e = &f;
	*c = *a;
	*e = *b;
	*a = *e;
	*b = *c;
}
