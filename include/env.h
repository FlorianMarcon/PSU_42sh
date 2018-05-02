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

int	len_env_list(env_t *list);

int	my_str_char_len(char *cmd, char sep);

#endif
