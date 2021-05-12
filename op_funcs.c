#include "monty.h"


/**
 * push - push a value to the main stack
 * @stack: top of the stack/ head of doubly linked list
 * @line_number: line number of the instruction
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	int operand = 0;
	int *operand_ptr = &operand;
	list_t *instruction = NULL;
	list_t *cursor = monty_file_content;
	stack_t *top = NULL;

	while (cursor != NULL)
	{
		if (cursor->line_n == line_number)
		{
			instruction = cursor;
			break;
		}
	}
	get_operand(instruction->str, operand_ptr);
	if (operand_ptr == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_list(monty_file_content);
		/*free stack*/
		exit(EXIT_FAILURE);
	}
	top = push_value(stack, operand);
	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_list(monty_file_content);
		/*free stack*/
		exit(EXIT_FAILURE);
	}
}


/**
 * pall - prints the stack
 * @stack: top of the stack/ head of doubly linked list
 * @line_number: line number of the instruction
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *cursor = *stack;

	for (i = 0; cursor != NULL; i++)
	{
		printf("%d\n", cursor->n);
		cursor = cursor->next;
	}
}
