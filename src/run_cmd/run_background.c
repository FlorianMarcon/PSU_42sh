/*
** EPITECH PROJECT, 2017
** run_background
** File description:
** run_background
*/

#include <unistd.h>
#include "header_shell.h"

int	run_background(shell_t *shell, tree_t *node)
{
	pid_t *pid = malloc(sizeof(*pid));
	char **cmd;
	char *path;

	if (node->left == NULL || (cmd = (char **)node->left->data) == NULL)
		return (1);
	if ((path = get_path(shell->binary, cmd[0])) == NULL)
		return (1);
	*pid = fork();
	if (*pid == 0) {
		if (execve(path, cmd, shell->arr_env) == -1) {
			fprintf(stderr, "%s: Command not found.\n", cmd[0]);
			exit (1);
		}
	}
	if (shell->process_back == NULL)
		shell->process_back = create_list(pid);
	else
		create_node(shell->process_back, pid);
	return (0);
}
