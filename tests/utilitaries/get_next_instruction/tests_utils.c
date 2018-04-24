/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "header_shell.h"
#include "tree.h"

Test(get_next_instruction, test1)
{
	int fd = open("./data/command_line_one.test", O_RDONLY);
	tree_t *tree;
	shell_t shell;

	cr_assert_neq(fd, -1);
	tree = get_next_instruction(&shell, fd);
	cr_assert_neq(tree, NULL);
	free(tree);
	tree = get_next_instruction(&shell, fd);
	cr_assert_eq(tree, NULL);
	tree = get_next_instruction(&shell, fd);
	cr_assert_eq(tree, NULL);
}
