#include "monty.h"


/**
 * is_valid - validates if a string is a valid instruction
 * @line: string to be checked
 *
 * Return: 1 if valid, 0 otherwise
 */
int is_valid(char *line)
{
	int i;
	char *opcodes[] = {"push", "pall", "pint", "pop", "swap", "add", "sub", "div", 
			   "mul", "mod", "pchar", "pstr", "rotl", "rotr", "stack", "queue", NULL};
	char *temp = strdup(line);
	char *first_string = strtok(temp, " ");
	for (i = 0; opcodes[i] != NULL; i++)
	{
		if (strcmp(first_string, opcodes[i]) == 0)
		{
			free(temp);
			return (1);
		}
	}
	free(temp);
	return (0);
}

/**
 * remove_newline - removes new line from a string
 * @str: string to be used
 *
 * Return: void
 */
void remove_newline(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			break;
		i++;
	}
	str[i] = '\0';
}
