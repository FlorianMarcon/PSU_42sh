/*
** EPITECH PROJECT, 2017
** my_str_isprintable
** File description:
** my_str_isprintable.c
*/

int	my_str_isprintable(char const *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] > 126 || str[i] < 32)
			return (0);
		else
			i++;
	}
	return (1);
}
