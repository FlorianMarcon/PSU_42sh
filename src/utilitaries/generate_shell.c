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
	hm_object_t *obj;
	char *str = NULL;

	shell->arr_env = envp;
	shell->list_env = init_env(envp);
	shell->env = generate_hm_env(shell->list_env);
	getcwd(shell->pwd, sizeof(shell->pwd));
	shell->old_pwd = NULL;
	obj = hm_get_object(shell->env, "PATH");
	if (obj != NULL)
		str = (char *)obj->data;
	shell->binary = generate_hm_binary(str);
	shell->value_exit = 0;
	shell->exit = false;
	shell->process_back = NULL;
	shell->list_local = NULL;
	return (0);
}
