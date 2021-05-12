#include "monty.h"


/**
 * push_value - pushes a number to the top of a stack
 * @head: top of the stack/ head of doubly linked list
 * @n: number to be pushed
 *
 * Return: the address of the new element
 */
stack_t *push_value(stack_t **head, int n)
{
	stack_t *new = NULL;

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
	new->next = *head;
	(*head)->prev = new;
	*head = new;

	return (new);
}

/**
 * pop_value - pops the top of a stack
 * @head: top of the stack/ head of doubly linked list
 *
 * Return: the removed element
 */
stack_t *pop_value(stack_t **head)
{
	int i;
	stack_t *popped = NULL;

	if (head == NULL)
		return (NULL);
	if (cursor == NULL)
		return (NULL);
	popped = *head;
	(*head) = (*head)->next;
	(*head)->prev = NULL;
	return (popped);
}

/**
 * print_stack - prints a stack to STDOUT
 * @h: top of the stack/ head of doubly linked list
 *
 * Return: void
 */
void print_stack(stack_t *h)
{
	stack_t *cursor = h;

	for (i = 0; cursor != NULL; i++)
	{
		printf("%d\n", cursor->n);
		cursor = cursor->next;
	}
}

/**
 * get_value - gets the top of the stack
 * @head: top of the stack/ head of doubly linked list
 *
 * Return: the top of the stack
 */
stack_t *get_value(stack_t *head)
{
	if (head == NULL)
		return (NULL);
	return (head);
}
