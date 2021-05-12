#include <stdlib.h>
#include <string.h>
#include "monty.h"


/**
 * get_opcode - gets the opcode from an instruction
 * @instruction: instruction to be checked
 * @store: buffer to store the opcode in
 *
 * Return: void
 */
void get_opcode(char *instruction, char *store)
{
	char *temp = strdup(instruction);
	strcpy(store, strtok(temp, " "));
	free(temp);
}


/**
 * get_operand - gets the operand from an instruction
 * @instruction: instruction to be checked
 * @store: integer to store the operand in
 *
 * Return: void
 */
void get_operand(char *instruction, int *store __attribute__((unused)))
{
	char *temp = strdup(instruction);
	char *temp_2 = strtok(temp, " ");
	int flag = 0;
	temp_2 = strtok(NULL, " ");
	if (temp_2 == NULL)
		store = NULL;
	else
	{
		while (*temp_2)
		{
			if ((*temp_2 < 48) && (*temp_2 > 57))
			{
				flag = 1;
				store = NULL;
				break;
			}
		}
	}
	if (!flag)
		*store = atoi(temp_2);
	free(temp);
}
