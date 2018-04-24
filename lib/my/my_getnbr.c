/*
** EPITECH PROJECT, 2017
** my_getnbr.c
** File description:
** obternir un nb dans une str
*/

#include "my.h"

int	my_signe(char const *str)
{
	int signe = 1;
	int i = 0;

	while ((str[i] == '+' || str[i] == '-')) {
		if (str[i] == '-')
			signe *= (-1);
		i++;
	}
	return (signe);
}

int	obtain_nbr(int i, int a, char const *str)
{
	int resultat = 0;
	int unite = 0;

	i = i - a;
	for (; a != 0; a--) {
		while (unite != str[i] - 48)
			unite++;
		resultat = (resultat * 10) + unite;
		i++;
		unite = 0;
	}
	return (resultat);
}
int	my_getnbr(char const *str)
{
	int i = 0;
	int a = 0;
	int resultat;
	int signe;

	while (str[i] != '\0' && (str[i] < 47 || str[i] > 58))
		i++;
	signe = my_signe(str);
	while (str[i] < 58 && str[i] > 47) {
		a++;
		i++;
	}
	resultat = obtain_nbr(i, a, str);
	if (resultat > 2147483647)
		return (0);
	resultat *= signe;
	return (resultat);
}
