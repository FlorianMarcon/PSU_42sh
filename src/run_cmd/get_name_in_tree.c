/*
** EPITECH PROJECT, 2017
** get_name_in_tree
** File description:
** get_name_in_tree
*/

#include "tree.h"
#include "my.h"

char	*get_name_in_tree(tree_t *tree)
{
	char **tab;

	if (tree == NULL || (tab = (char **)tree->data) == NULL)
		return (NULL);
	if (len_tab(tab) != 1)
		return (NULL);
	return (tab[0]);
}
