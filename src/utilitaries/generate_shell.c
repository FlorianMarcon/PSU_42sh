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

unsigned int	generate_shell(char **envp, shell_t *shell)
{
	variable_t *var = NULL;

	shell->arr_env = envp;
	shell->list_env = init_env(envp);
	getcwd(shell->pwd, sizeof(shell->pwd));
	shell->old_pwd = get_old_pwd(shell->list_env);
	var = search_variable("PATH", shell->list_env);
	shell->binary = generate_hm_binary(var->data);
	shell->value_exit = 0;
	shell->exit = false;
	shell->process_back = NULL;
	shell->list_local = NULL;
	shell->list_alias = NULL;
	shell->size_history = 30;
	for ( int i = 0; i != shell->size_history; i++)
		shell->history[i] = NULL;
	shell->mem = NULL;
	return (0);
}
