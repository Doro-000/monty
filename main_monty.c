#include <stdio.h>
#include "monty.h"

int main(int argc, char *argv[])
{
	stack_t *main_stack = NULL;
	char *current_line = NULL, *current_opcode;
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
		if (!is_valid(current_line))
			invalid_opcode(&current_line, line_num);
		current_opcode = get_opcode(current_line);
		execute_opcode(current_opcode, &main_stack, line_num);
		line_num++;
	}
	free(current_line);
	return (0);
}
