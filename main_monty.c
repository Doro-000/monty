#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

list_t *monty_file_content = NULL;

/**
 * main - entry point, monty 0.98 interpreter
 * @argc: number of arguments passed to the program
 * @argv: list of arguments
 *
 * Return: always 0, exit with EXIT_FAILIURE on any error
 */
int main(int argc, char *argv[])
{
	stack_t *main_stack = NULL;
	list_t *cursor = monty_file_content;
	char *current_line = NULL;
	int n = 0, line_num = 1;
	FILE *monty_file = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty_file = fopen(argv[1], "r");
	if (monty_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", "HANDLE LATER");
		exit(EXIT_FAILURE);
	}
	while (getline(&current_line, &n, monty_file) != -1)
	{
		if (add_node_end(&monty_file_content, current_line, line_num) == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free_list(monty_file_content);
			free(current_line);
			exit(EXIT_FAILURE);
		}
		line_num++;
	}
	free(current_line);
	while (cursor != NULL)
	{
		execute_instruction(&stack, cursor);
		cursor = cursor->next;
	}
	free_list(monty_file_content);
	return (0);
}

void execute_instruction(stack_t **stack, list_t *instruction)
{
	instruction_t opcode_map[] = {
		{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add}
	};
	int i, temp;
	char current_opcode[10];
	void (*current_f)(stack_t **stack, unsigned int line_number);

	if (strlen(instruction->str) == 0)
		return;
	if (!is_valid(instruction->str))
	{
		temp = instruction->line_n /*betty*/
		fprintf(stderr, "L%d: unknown instruction %s", temp, strtok(instruction->str, " "));
		free(monty_file_content);
		exit(EXIT_FAILURE);
	}
	get_opcode(instruction->str, current_opcode);
	for (i = 0; i < 6; i++)
	{
		if (strcmp(current_opcode, opcode_map[i].opcode) == 0)
		{
			current_f = opcode_map[i].f;
			break;
		}
	}
	current_f(&stack, instruction->line_n);
}
