/*
** EPITECH PROJECT, 2017
** run_pipe
** File description:
** run_pipe
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "header_shell.h"
#include "tree.h"

int	*create_pipe(void)
{
	int *fd = malloc(sizeof(*fd) * 2);

	if (fd == NULL)
		return (NULL);
	if (pipe(fd) == -1) {
		free(fd);
		return (NULL);
	}
	return (fd);
}
int	run_pipe(shell_t *shell, tree_t *tree)
{
	int *fd = create_pipe();
	pid_t pid;
	int lock;
	int stdout = dup(1);

	if (fd == NULL)
		return (1);
	if ((pid = fork()) == 0) {
		dup2(fd[0], 0);
		close(fd[1]);
		run_cmd(shell, tree->right);
		exit(0);
	}
	dup2(fd[1], 1);
	run_cmd(shell, tree->left);
	close(fd[1]);
	dup2(stdout, 1);
	waitpid(pid, &lock, 0);
	free(fd);
	return (0);
}
