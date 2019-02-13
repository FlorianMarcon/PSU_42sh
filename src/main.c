/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#include "binary.h"
#include "header_shell.h"
#include "gnl_custom.h"

int	main(int ac, char **av, char **envp)
{
	shell_t shell;
	int res;
	struct termios term_old;
	struct termios term_new;

	tcgetattr(0, &term_old);
	if (isatty(0))
		gnl_custom_set_terminal(&term_new);
	if (ac > 1 || av[1] != NULL)
		return (1);
	if (generate_shell(envp, &shell))
		return (84);
	res = minishell(&shell);
	hm_destroy(shell.binary);
	tcsetattr(0, TCSADRAIN, &term_old);
	return (res);
}
