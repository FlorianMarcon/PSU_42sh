/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <termios.h>
#include <curses.h>
#include <unistd.h>
#include <term.h>
#include "gnl_custom.h"

void	set_terminal(struct termios *termios_p);

int	main(int ac, char **av)
{
	bool exit = false;
	char *str = NULL;
	struct termios old;
	struct termios new;

	if (ac > 1)
		return (84);
	tcgetattr(0, &old);
	set_terminal(&new);
	printf("Welcom in %s\n", av[0]);

	while (exit == false) {
		str = gnl_custom();

		if (str != NULL) {
			if (strlen(str) > 0)
				printf("%s\n", str);
			if (strcmp(str, "exit") == 0 || strcmp(str, "q") == 0)
				exit = true;
			free(str);
			str = NULL;
		} else {
			exit = true;
			fprintf(stderr, "str equal NULL\n");
		}
	}
	tcsetattr(0, TCSADRAIN, &old);
	return (0);
}

void	set_terminal(struct termios *term)
{
	char *name = getenv("TERM");

	if (name == NULL)
		return;
	if (tgetent(NULL, name) == ERR || tcgetattr(0, term) == -1)
		return;
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	tcsetattr(0, TCSADRAIN, term);
}
