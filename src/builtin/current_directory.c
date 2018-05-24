/*
** EPITECH PROJECT, 2017
** current_directory
** File description:
** current_directory
*/

#include <unistd.h>
#include <string.h>
#include "my.h"
#include "header_shell.h"

int	current_directory_move(shell_t *shell, char *path)
{
	if (chdir(path)) {
		fprintf(stderr, "%s: No such file or directory.\n", path);
		return (1);
	}
	if (shell->old_pwd != NULL)
		free(shell->old_pwd);
	shell->old_pwd = my_strdup(shell->pwd);
	getcwd(shell->pwd, sizeof(shell->pwd));
	return (0);
}
int	current_directory(shell_t *shell, char **cmd)
{
	char *path = NULL;
	int ret;

	if (len_tab(cmd) > 2) {
		fprintf(stderr, "cd: Too many arguments.\n");
		return (1);
	}
	if (len_tab(cmd) == 2) {
		if (my_strcmp(cmd[1], "-") == 0 && shell->old_pwd)
			path = strdup(shell->old_pwd);
		else
			path = strdup(cmd[1]);
	} else
		path = strdup("/home");
	ret = current_directory_move(shell, path);
	free(path);
	return (ret);
}
