/*
** EPITECH PROJECT, 2017
** generate_shell
** File description:
** generate_shell
*/

#include <unistd.h>
#include <stdbool.h>
#include <termios.h>
#include <unistd.h>
#include "header_shell.h"
#include "hash_map.h"
#include "variable.h"
#include "binary.h"

void	generate_shell_indexe(char **envp, shell_t *shell)
{
	char *secour = "/home/marcon/bin:/home/marcon/.local/bin:/usr/local/sbin\
:/usr/local/bin:/usr/sbin:/usr/bin:/sbin\
:/bin:/usr/games:/usr/local/games:/snap/bin";
	variable_t *var = NULL;

	shell->arr_env = envp;
	shell->list_env = init_env(envp);
	getcwd(shell->pwd, sizeof(shell->pwd));
	shell->old_pwd = get_old_pwd(shell->list_env);
	var = search_variable("PATH", shell->list_env);
	if (var != NULL && var->data != NULL)
		shell->binary = generate_hm_binary(var->data);
	else
		shell->binary = generate_hm_binary(secour);
}
unsigned int	generate_shell(char **envp, shell_t *shell)
{
	generate_shell_indexe(envp, shell);
	shell->value_exit = 0;
	shell->exit = false;
	shell->process_back = NULL;
	shell->list_local = NULL;
	shell->list_alias = NULL;
	shell->size_history = 30;
	for (int i = 0; i != shell->size_history; i++)
		shell->history[i] = NULL;
	shell->mem = NULL;
	return (0);
}
