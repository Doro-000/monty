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
	list_t *cursor = NULL, *temp = NULL;
	char *current_line = NULL;
	unsigned int line_num = 1;
	size_t n = 0;
	FILE *monty_file = NULL;


	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty_file = fopen(argv[1], "r");
	if (monty_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&current_line, &n, monty_file) != -1)
	{
		temp = add_node_end(&monty_file_content, current_line, line_num++);
		if (temp == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free_list(monty_file_content);
			free(current_line);
			exit(EXIT_FAILURE);
		}
	}
	free(current_line);
	fclose(monty_file);
	cursor = monty_file_content;
	while (cursor != NULL)
	{
		execute_instruction(&main_stack, cursor);
		cursor = cursor->next;
	}
	free_list(monty_file_content);
	return (0);
}

/**
 * execute_instruction - executes an instruction
 * @stack: stack to be used
 * @instruction: instruction node containing info about the instruction
 *
 * Return: void
 */
void execute_instruction(stack_t **stack, list_t *instruction)
{
	instruction_t opcode_map[] = {
		{"push", push}, {"pall", pall}
	};
	int i, line_n;
	char current_opcode[10], *invalid_inst;
	void (*current_f)(stack_t **stack, unsigned int line_number) = NULL;

	if (strlen(instruction->str) == 0)
		return;
	if (!is_valid(instruction->str))
	{
		line_n = instruction->line_n; /*betty*/
		invalid_inst = strtok(instruction->str, " ");
		fprintf(stderr, "L%d: unknown instruction %s", line_n, invalid_inst);
		free_list(monty_file_content);
		/*free stack*/
		exit(EXIT_FAILURE);
	}
	get_opcode(instruction->str, current_opcode);
	for (i = 0; i < 2; i++)
	{
		if (strcmp(current_opcode, opcode_map[i].opcode) == 0)
		{
			current_f = opcode_map[i].f;
			break;
		}
	}
	current_f(stack, instruction->line_n);
}
