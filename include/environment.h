/*
** EPITECH PROJECT, 2017
** environnement
** File description:
** environnement
*/

#ifndef ENV_
#define ENV_

#include "my.h"
#include "hash_map.h"

typedef struct variable {
	char *name;
	char *data;
}variable_t;

// generate_hm_env

linked_list_t	*generate_arg_var_env(char *arg);

char	*generate_name_var_env(char *str);

hash_map_t	*generate_hm_env(linked_list_t *list);

linked_list_t	*generate_list_env(char **envp);

#endif
