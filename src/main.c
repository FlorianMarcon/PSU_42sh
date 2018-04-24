/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#include <sys/types.h>
#include <dirent.h>
#include "binary.h"
#include "header_shell.h"

int	main(int ac, char **av, char **envp)
{
	(void)av;
	shell_t *shell;
	int res;

	if (ac > 1)
		return (1);
	shell = generate_shell(envp);
	if (shell == NULL)
		return (84);
	res = minishell(shell);
	hm_destroy(shell->env);
	hm_destroy(shell->binary);
	free(shell);
	return (res);
}
