#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_node - insert a number in a sorted linked list
 * @number: number to insert
 * @head: head of a linked list
 * Return: pointer to new node
 *
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new = malloc(sizeof(listint_t));
	listint_t *current = *head;

	if (new == NULL)
		return (NULL);

	new->n = number;


	if (*head == NULL || number < (*head)->n)
	{
		new->next = *head;
		*head = new;
		return (new);
	}


	while (current->next != NULL && current->next->n <= number)
	{
		current = current->next;
	}

	new->next = current->next;
	current->next = new;

	return (new);
}
