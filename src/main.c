/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#include <sys/types.h>
#include <ncurses.h>
#include <dirent.h>
#include "binary.h"
#include "header_shell.h"

int	main(int ac, char **av, char **envp)
{
	shell_t shell;
	int res;

	(void)av;

	if (ac > 1)
		return (1);
	if (generate_shell(envp, &shell) == NULL)
		return (84);
	res = minishell(&shell);
	hm_destroy(shell.env);
	hm_destroy(shell.binary);
//	tcsetattr(0, 0, &shell.old_termios_s);
	return (res);
}
