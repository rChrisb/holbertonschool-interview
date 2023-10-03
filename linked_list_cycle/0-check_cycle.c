#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * check_cycle -  checks if a singly linked list has a cycle in it.
 *
 * @list: list to be checked
 * Return: 0 if there is no cycle, 1 if there is a cycle.
 */

int check_cycle(listint_t *list)
{
	listint_t *first = list;
	listint_t *second = list;

	if (list == NULL)
	{
		return (0);
	}
	while (second != NULL && second->next != NULL)
	{
		first = first->next;
		second = second->next->next;
		if (first == second)
		{
			return (1);
		}

	}
	return (0);
}
