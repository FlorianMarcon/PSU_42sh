/*
** EPITECH PROJECT, 2017
** gnl_custom_set_terminal
** File description:
** gnl_custom_set_terminal
*/

#include <termios.h>
#include <curses.h>
#include <unistd.h>
#include <termios.h>

void	gnl_custom_set_terminal(struct termios *term)
{
	if (tcgetattr(0, term) == -1)
		return;
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	tcsetattr(0, TCSADRAIN, term);
}
