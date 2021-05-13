#include "monty.h"


/**
 * add - adds the top two elements of the stack
 * @stack: top of the stack/ head of doubly linked list
 * @line_number: line number of the instruction
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_1 = NULL, *temp_2 = NULL;

	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short", line_number);
		free_stack(*stack);
		free_list(monty_file_content);
		exit(EXIT_FAILURE);
	}
	temp_1 = pop_value(stack);
	temp_2 = pop_value(stack);
	push_value(stack, temp_1->n + temp_2->n);
}

/**
 * nop - doesn't do anything
 * @stack: top of the stack/ head of doubly linked list
 * @line_number: line number of the instruction
 *
 * Return: void
 */
void nop(stack_t **stack __attribute__((unused)), unsigned int line_number __attribute__((unused)))
{
	;
}
