/*
** EPITECH PROJECT, 2017
** where
** File description:
** where
*/

#include "header_shell.h"
#include "hash_map.h"
#include "binary.h"

int	which(shell_t *shell, char **cmd)
{
	hm_object_t *obj;

	if (len_tab(cmd) < 2) {
		fprintf(stderr, "which: Too few arguments.\n");
		return (1);
	}
	for (unsigned int i = 1; cmd[i] != NULL; i++) {
		obj = hm_get_object(shell->binary, cmd[i]);
		if (is_builtin(cmd[i]))
			fprintf(stderr, "%s: shell built-in command.\n", cmd[i]);
		else if (obj != NULL && obj->data != NULL) {
			dprintf(1, "%s\n", (char *)obj->data);
		} else
			dprintf(1, "%s: Command not found.\n", cmd[i]);
	}
	return (0);
}
