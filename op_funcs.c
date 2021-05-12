#include "monty.h"


void push(stack_t **stack, unsigned int line_number)
{
	int operand = 0;
	int *operand_ptr = &operand;
	list_t *instruction = NULL;
	list_t *cursor = monty_file_content;

	while (cursor != NULL)
	{
		if (cursor->line_n == line_number)
		{
			instruction = cursor;
			break;
		}
	}
	get_operand(instruction->str, operand_ptr)
	
}