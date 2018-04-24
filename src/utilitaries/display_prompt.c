/*
** EPITECH PROJECT, 2017
** display_prompt
** File description:
** display_prompt
*/

#include <unistd.h>
#include "my.h"
#include "header_shell.h"

void	display_prompt(shell_t *shell)
{
	char *prompt = shell->pwd;

	if (prompt == NULL)
		return;
	if (isatty(0))
		my_printf("%s:-> ", prompt);
}
