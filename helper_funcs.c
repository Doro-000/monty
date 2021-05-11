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
 * add_node_end - adds a node to the end of a linked list
 * @head: pointer to the head of the list
 * @str: string to be used as content of the newly added node
 *
 * Return: address of the newly added node
 */
list_t *add_node_end(list_t **head, char *str)
{
	list_t *new_node;
	list_t *cursor = *head;

	new_node = malloc(sizeof(list_t));
	if (new_node != NULL)
	{
		new_node->str = strdup(str);
		new_node->next = NULL;
	}
	else
		return (NULL);
	if (cursor != NULL)
	{
		while (cursor->next != NULL)
			cursor = cursor->next;
		cursor->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}

/**
 * free_list - frees a linked list
 * @head: head of the list
 *
 * Return: void
 */
void free_list(list_t *head)
{
	list_t *temp;

	if (head != NULL)
	{
		while (head != NULL)
		{
			temp = head;
			head = head->next;
			free(temp->str);
			free(temp);
		}
	}
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
