/*
** EPITECH PROJECT, 2017
** get_next_instruction
** File description:
** get_next_instruction
*/

#include "tree.h"
#include "my.h"
#include "header_shell.h"
#include "gnl_custom.h"

// ici tout le parsing sous for de string

char	*preparsing(char *str)
{
	str = separation_between_instruction_operator(str);
	return (str);
}

// ici tout le parsing sous form de tableau

char	**postparsing(char **tab)
{
	for (unsigned int i = 0; tab[i] != NULL; i++) {

	}
	return (tab);
}

tree_t	*get_next_instruction(shell_t *shell, int fd)
{
	char *str = NULL;
	char **tab;
	tree_t *cmd;

	(void)shell;
	if (isatty(0)) {
		str = gnl_custom(shell);
		put_instruction_in_history(shell, str);
	}
	else
		str = get_next_line(fd);
	if (str == NULL)
		return (NULL);
	str = preparsing(str);
	if ((tab = parsing_str(str, ' ' | '\t')) == NULL)
		return (NULL);
	tab = postparsing(tab);
	if ((cmd = parsing_command_line(tab)) == NULL)
		cmd = tree_create_node(NULL, NULL, NULL);
	free(str);
	free(tab);
	return (cmd);
}
