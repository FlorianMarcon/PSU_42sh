/*
** EPITECH PROJECT, 2017
** parsing_command_line
** File description:
** parsing_command_line
*/

#include <stdlib.h>
#include "my.h"
#include "header_shell.h"
#include "tree.h"

char	**create_tab_op_for_command_line(char *str)
{
	char **tab = malloc(sizeof(*tab) * 2);

	if (tab == NULL)
		return (NULL);
	tab[0] = my_strdup(str);
	tab[1] = NULL;
	return (tab);
}
tree_t	*parsing_command_line(char **cmd)
{
	tree_t *tree = NULL;
	int i;
	char **op;
	char **dup;

	if (cmd == NULL || cmd[0] == NULL)
		return (NULL);
	if ((i = search_index_operator(cmd)) == -1) {
		dup = my_tabdup(cmd);
		tree = tree_create_node(dup, NULL, NULL);
	} else {
		op = create_tab_op_for_command_line(cmd[i]);
		if ((tree = tree_create_node(op, NULL, NULL)) == NULL)
			return (NULL);
		free(cmd[i]);
		cmd[i] = NULL;
		tree_link_node(tree, parsing_command_line(&cmd[i + 1]),
		parsing_command_line(cmd));
	}
	return (tree);
}
