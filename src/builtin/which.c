/*
** EPITECH PROJECT, 2017
** where
** File description:
** where
*/

#include "header_shell.h"
#include "hash_map.h"
#include "binary.h"

int	which(shell_t *shell, char **cm)
{
	hm_object_t *obj;

	if (len_tab(cm) < 2) {
		fprintf(stderr, "which: Too few arguments.\n");
		return (1);
	}
	for (unsigned int i = 1; cm[i] != NULL; i++) {
		obj = hm_get_object(shell->binary, cm[i]);
		if (is_builtin(cm[i]))
			fprintf(stderr, "%s: shell built-in command.\n", cm[i]);
		else if (obj != NULL && obj->data != NULL) {
			dprintf(1, "%s\n", (char *)obj->data);
		} else
			dprintf(1, "%s: Command not found.\n", cm[i]);
	}
	return (0);
}
