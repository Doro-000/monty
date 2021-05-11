#include "monty.h"


/**
 * push_value - pushes a number to the top of a stack
 * @head: bottom of the stack
 * @n: number to be pushed
 *
 * Return: the address of the new element
 */
stack_t *push_value(stack_t **head, int n)
{
	int i;
	stack_t *new = NULL;
	stack_t *cursor = *head;

	new = malloc(sizeof(*new));
	if (new == NULL || head == NULL)
		return (NULL);
	new->n = n;
	new->prev = NULL;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	for (i = 0; cursor->next != NULL; i++)
		cursor = cursor->next;
	cursor->next = new;
	new->prev = cursor;

	return (new);
}
