/*
** EPITECH PROJECT, 2017
** 42_sh
** File description:
** env.h
*/

#ifndef ENV_
#define ENV_

typedef struct env_s {
	char *name;
	char *data;
	struct env_s *next;
} env_t;

char	*get_old_pwd(env_t *env);

void	env(env_t *envp);

void	set_env(char **cmd, env_t *envp);

void	unset_env(char **cmd, env_t *env);

char	**get_env(env_t *env);

env_t	*init_env(char **envp);

int	len_env_list(env_t *list);

int	my_str_char_len(char *cmd, char sep);

#endif
