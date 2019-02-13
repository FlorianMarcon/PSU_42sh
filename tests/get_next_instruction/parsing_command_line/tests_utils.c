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
#include "get_next_line.h"
#include "my.h"

char	**get_cmd_line_test(char *str)
{
	int fd = open(str, O_RDONLY);
	char **tab;

	if (fd == -1 || (str = get_next_line(fd)) == NULL)
		return (NULL);
	tab = parsing_str(str, ' ' | '\t');
	close(fd);
	return (tab);
}
Test(get_cmd_line_test, test1)
{
	char **tab = get_cmd_line_test("./data/good_command_line.test");

	cr_assert_neq(tab, NULL);
	cr_assert_str_eq(tab[0], "ls");
	cr_assert_str_eq(tab[1], "-l");
	cr_assert_str_eq(tab[2], ">");
	cr_assert_str_eq(tab[3], "file");
	cr_assert_str_eq(tab[4], ";");
	cr_assert_str_eq(tab[5], "cat");
	cr_assert_str_eq(tab[6], "file");
	cr_assert_str_eq(tab[7], "&");
	cr_assert_str_eq(tab[8], "ls");
	cr_assert_str_eq(tab[9], "-l");
}

Test(create_tab_op_for_command_line, test1)
{
	char **tab = create_tab_op_for_command_line("salut");

	cr_assert_neq(tab, NULL);
	cr_assert_eq(tab[1], NULL);
	cr_assert_str_eq(tab[0], "salut");
}
Test(parsing_command_line, test1)
{
	char **tab = get_cmd_line_test("./data/good_command_line.test");
	tree_t *tree = parsing_command_line(tab);
	char **tmp;

	cr_assert_neq(tree, NULL);
	tmp = (char **)tree->data;
	cr_assert_neq(tmp, NULL);
	cr_assert_str_eq(tmp[0], ";");
	tmp = (char **)tree->left->data;
	cr_assert_neq(tmp, NULL);
	cr_assert_str_eq(tmp[0], ">");
	tmp = (char **)tree->left->left->data;
	cr_assert_neq(tmp, NULL);
	cr_assert_str_eq(tmp[0], "ls");
	cr_assert_str_eq(tmp[1], "-l");
	tmp = (char **)tree->left->right->data;
	cr_assert_neq(tmp, NULL);
	cr_assert_str_eq(tmp[0], "file");
	cr_assert_eq(tmp[1], NULL);
}
Test(parsing_command_line, test2)
{
	char **tab = get_cmd_line_test("./data/good_command_line.test");
	tree_t *tree = parsing_command_line(tab);
	char **tmp;

	cr_assert_neq(tree, NULL);
	tmp = (char **)tree->data;
	cr_assert_neq(tmp, NULL);
	tmp = (char **)tree->right->data;
	cr_assert_neq(tmp, NULL);
	cr_assert_str_eq(tmp[0], "&");
	tmp = (char **)tree->right->right->data;
	cr_assert_neq(tmp, NULL);
	cr_assert_str_eq(tmp[0], "ls");
	cr_assert_str_eq(tmp[1], "-l");
	tmp = (char **)tree->right->left->data;
	cr_assert_neq(tmp, NULL);
	cr_assert_str_eq(tmp[0], "cat");
	cr_assert_str_eq(tmp[1], "file");
}
