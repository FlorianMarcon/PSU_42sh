/*
** EPITECH PROJECT, 2017
** run_background
** File description:
** run_background
*/

#include <string.h>
#include <unistd.h>
#include "header_shell.h"

void	add_processus_list_back(shell_t *shell, pid_t *pid, char **cmd)
{
	char *str = cmd[0];

	for (unsigned int i = 1; cmd[i] != NULL; i++)
		str = strcat(str, cmd[i]);
	if (shell->process_back == NULL)
		shell->process_back = create_list(create_variable(str, pid));
	else
		add_data_in_list(str, pid, shell->process_back);
}
int	run_background(shell_t *shell, tree_t *node)
{
	pid_t *pid = malloc(sizeof(*pid));
	char **cmd;
	char *path;

	if (node->left == NULL || (cmd = (char **)node->left->data) == NULL)
		return (1);
	if ((path = get_path(shell->binary, cmd[0])) == NULL || pid == NULL)
		return (1);
	*pid = fork();
	if (*pid == 0) {
		if (execve(path, cmd, shell->arr_env) == -1) {
			fprintf(stderr, "%s: Command not found.\n", cmd[0]);
			exit (1);
		}
	}
	add_processus_list_back(shell, pid, cmd);
	return (0);
}
