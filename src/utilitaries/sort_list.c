/*
** EPITECH PROJECT, 2017
** sort_list
** File description:
** sort_list
*/

#include "variable.h"
#include "my.h"

void	sort_list(linked_list_t *list)
{
	variable_t *first = NULL;
	variable_t *second = NULL;
	linked_list_t *start = list;

	if (list == NULL)
		return;
	while (list->next != NULL) {
		first = (variable_t *)list->data;
		second = (variable_t *)list->next->data;
		if (my_strcmp(first->name, second->name) > 0) {
			list->data = second;
			list->next->data = first;
			list = start;
		} else
			list = list->next;
	}
}
