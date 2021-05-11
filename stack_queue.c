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

/**
 * pop_value - pops the top of a stack
 * @head: bottom of the stack
 *
 * Return: the removed element
 */
stack_t *pop_value(stack_t **head)
{
	int i;
	stack_t *cursor = *head;
	stack_t *popped = NULL;

	if (head == NULL)
		return (NULL);
	if (cursor == NULL)
		return (NULL);
	if (cursor->next == NULL)
	{
		popped = cursor;
		(*head) = NULL;
		return (popped);
	}
	for (i = 0; cursor->next != NULL; i++)
		cursor = cursor->next;
	popped = cursor;
	(popped->prev)->next = NULL;
	popped->prev = NULL;
	return (popped);
}

/**
 * print_stack - prints a stack to STDOUT
 * @h: bottom of the stack
 *
 * Return: void
 */
void print_stack(stack_t *h)
{
	stack_t *cursor = h;

	for (i = 0; cursor->next != NULL; i++)
		cursor = cursor->next;
	for (i = 0; cursor != NULL; i++)
	{
		printf("%d\n", cursor->n);
		cursor = cursor->prev;
	}
}

/**
 * get_value - gets the top of the stack
 * @head: bottom of the stack
 *
 * Return: the top of the stack
 */
stack_t *get_value(stack_t *head)
{
	int i;
	stack_t *cursor = head;

	if (cursor == NULL)
		return (NULL);
	for (i = 0; cursor->next != NULL; i++)
		cursor = cursor->next;
	return (cursor);
}
