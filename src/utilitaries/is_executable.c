/*
** EPITECH PROJECT, 2017
** is_executable
** File description:
** is_executable
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int	is_executable(char *path)
{
	if (access(path, X_OK) == 0)
		return (1);
	return (0);
}
