/*
** EPITECH PROJECT, 2017
** exec
** File description:
** exec
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"
#include "header_shell.h"
#include "binary.h"
#include "hash_map.h"

void	get_return(shell_t *shell, int lock)
{
	if (WIFEXITED(lock))
		shell->value_exit = WEXITSTATUS(lock);
	if (WIFSIGNALED(lock))
		shell->value_exit = WSTOPSIG(lock);
}
int	basic_exec(shell_t *shell, char **cmd)
{
	pid_t pid;
	char *path = get_path(shell->binary, cmd[0]);
	int lock = 1;

	if (path == NULL)
		return (1);
	pid = fork();
	if (pid == 0) {
		if (execve(path, cmd, shell->arr_env) == -1) {
			fprintf(stderr, "%s: Command not found.\n", cmd[0]);
			exit (0);
		}
	}
	waitpid(pid, &lock, 0);
	return (lock);
}

// il faut gerer les signaux
