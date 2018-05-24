/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** sync pwd
*/

#include "string.h"
#include "header_shell.h"

void	sync_pwd(shell_t *shell)
{
	add_data_in_list("PWD", shell->pwd, shell->list_env);
}
