/*
** EPITECH PROJECT, 2017
** run_left_chevron
** File description:
** run_left_chevron
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "header_shell.h"

int	run_left_chevron(shell_t *shell, tree_t *tree)
{
	char *file = get_name_in_tree(tree->right);
	int fd = open(file, O_RDONLY);
	int stdin = dup(0);

	if (fd == -1)
		return (1);
	dup2(fd, 0);
	run_cmd(shell, tree->left);
	close(fd);
	dup2(stdin, 0);
	return (0);
}
