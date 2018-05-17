/*
** EPITECH PROJECT, 2017
** minishell2
** File description:
** create_linked_env
*/

#include "env.h"

int	len_env_list(env_t *list)
{
	int i = 0;

	while (list->next != NULL) {
		list = list->next;
		i++;
	}
	return (i + 1);
}

void	create_node_env(env_t *env, char *data)
{
	env_t *new = malloc(sizeof(env_t) * 1);

	while (env->next != NULL)
		env = env->next;
	new->data = data;
	new->next = NULL;
	env->next = new;
}

/*env_t	*init_env(char **envp)
{
	env_t *env = malloc(sizeof(env_t) * 1);
	int i = 0;

	env->data = envp[i];
	env->next = NULL;
	while (envp[++i] != NULL) {
		create_node_env(env, envp[i]);
	}
	return (env);
}*/

linked_list_t	*init_env(char **envp)
{
	linked_list_t *env = malloc(sizeof(*env) * 1);
	int i = 0;

	env->data = envp[i];
	env->next = NULL;
	while (envp[++i] != NULL) {
		create_node(env, envp[i]);
	}
	return (env);
}

char	**get_env(linked_list_t *env)
{
	char **new = malloc(sizeof(char *) * (len_env_list(env) + 1));
	int i = 0;

	while (env->next != NULL) {
		new[i] = (char *)env->data;
		env = (env->next;
		i++;
	}

	return (new);
}
