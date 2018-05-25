/*
** EPITECH PROJECT, 2017
** put_instruction_in_history
** File description:
** put_instruction_in_history
*/

#include <string.h>
#include "header_shell.h"

void	put_instruction_in_history(shell_t *shell, char *str)
{
	int i = 0;

	if (str == NULL || shell == NULL)
		return;
	for (; shell->history[i] != NULL && i != shell->size_history; i++)
	if (i == shell->size_history) {
		free(shell->history[shell->size_history - 1]);
		i--;
	}
	for (; i != 0; i--)
		shell->history[i] = shell->history[i - 1];
	shell->history[0] = strdup(str);
}
