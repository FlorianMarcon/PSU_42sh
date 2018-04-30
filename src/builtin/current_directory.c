/*
** EPITECH PROJECT, 2017
** current_directory
** File description:
** current_directory
*/

#include <unistd.h>
#include "my.h"
#include "header_shell.h"

int	current_directory(shell_t *shell, char **cmd)
{
	char *path;

	if (len_tab(cmd) > 2)
		return (1);
	if (len_tab(cmd) == 2) {
		path = cmd[1];
		if (my_strcmp(path, "-") == 0)
			path = shell->old_pwd;
		if (chdir(path) == 0) {
			if (shell->old_pwd != NULL)
				free(shell->old_pwd);
			shell->old_pwd = my_strdup(shell->pwd);
			getcwd(shell->pwd, sizeof(shell->pwd));
		} else
			fprintf(stderr, "%s: No such file or directory.\n", cmd[1]);
	}
	return (0);
}
