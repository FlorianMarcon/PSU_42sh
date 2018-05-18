/*
** EPITECH PROJECT, 2018
** auto
** File description:
** completion
*/

char	*cut_my_str(char *str)
{
	int i = 0;

	while (str[i] != '/')
		i++;
	str = &str[i];
	return (str);
}

char	*auto_completion(char *str)
{
	char *str_cut = cut_my_str(str);
	return (str_cut);
}
