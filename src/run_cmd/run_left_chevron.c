/*
** EPITECH PROJECT, 2017
** run_left_chevron
** File description:
** run_left_chevron
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
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

int	write_for_double_left_chevron(tree_t *tree)
{
	char *str = NULL;
	char **data = (char **)tree->data;

	while ((str = get_next_line(0)) != NULL) {
		if (strcmp(str, data[0]) == 0)
			break;
		my_printf("%s\n", str);
		free(str);
	}
	return (0);
}
int	run_double_left_chevron(shell_t *shell, tree_t *tree)
{
	int stdout = dup(1);
	int *fd = create_pipe();
	pid_t pid;
	int lock;

	if ((pid = fork()) == 0) {
		dup2(fd[0], 0);
		close(fd[1]);
		run_cmd(shell, tree->left);
		exit(0);
	}
	dup2(fd[1], 1);
	write_for_double_left_chevron(tree->right);
	close(fd[1]);
	dup2(stdout, 1);
	waitpid(pid, &lock, 0);
	free(fd);
	return (0);
}
