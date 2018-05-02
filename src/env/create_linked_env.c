/*
** EPITECH PROJECT, 2017
** minishell2
** File description:
** create_linked_env
*/

#include "env.h"

void	put_in_list(char *cmd, env_t *env)
{
	int n = my_strlen(cmd);
	int f = my_str_char_len(cmd, '=');
	int i = -1;
	int j = -1;

	env->name = malloc(f);
	while (cmd[++i] != '=')
		env->name[i] = cmd[i];
	env->data = malloc(n - f);
	while (cmd[++i] != '\0')
		env->data[++j] = cmd[i];
	free (cmd);
}

void	create_node_env(env_t *env, char *data)
{
	env_t *new = malloc(sizeof(env_t) * 1);

	while (env->next != NULL)
		env = env->next;
	put_in_list(data, env);
	new->next = NULL;
	env->next = new;
}

env_t	*init_env(char **envp)
{
	env_t *env = malloc(sizeof(env_t) * 1);
	int i = 0;

	put_in_list(envp[i], env);
	env->next = NULL;
	while (envp[++i] != NULL) {
		create_node_env(env, envp[i]);
	}
	return (env);
}

char	**get_env(env_t *env)
{
	char **new = malloc(sizeof(char *) * (len_env_list(env) + 1));
	int i = 0;

	while (env->next != NULL) {
		new[i] = "\0";
		new[i] = my_strcat(new[i], env->name);
		new[i] = my_strcat(new[i], "=");
		new[i] = my_strcat(new[i], env->data);
		env = env->next;
		i++;
	}
	return (new);
}
