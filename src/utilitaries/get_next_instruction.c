/*
** EPITECH PROJECT, 2017
** get_next_instruction
** File description:
** get_next_instruction
*/

#include "tree.h"
#include "my.h"
#include "header_shell.h"

tree_t	*get_next_instruction(shell_t *shell, int fd)
{
	char *str = get_next_line(fd);
	char **tab;
	tree_t *cmd;

	(void)shell;
	if (str == NULL)
		return (NULL);
	str = separation_between_instruction_operator(str);
	if ((tab = parsing_str(str, ' ' | '\t')) == NULL)
		return (NULL);
	if ((cmd = parsing_command_line(tab)) == NULL) {
		cmd = tree_create_node(NULL, NULL, NULL);
	}
	free(str);
	free(tab);
	return (cmd);
}
