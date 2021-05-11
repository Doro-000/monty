#define MONTY_H
#ifndef MONTY_H

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 *Description: doublt linked list node structure for stack
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: structure to map an opcode with a function
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @line_n: line number
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * to store contents of a file
 */
typedef struct list_s
{
	char *str;
	int line_n;
	struct list_s *next;
} list_t;

/* stack_queue */
stack_t *push_value(stack_t **head, int n);
stack_t *pop_value(stack_t **head);
void print_stack(stack_t *h);
stack_t *get_value(stack_t *head);

/* helper_funcs */
int is_valid(char *line);
void remove_newline(char *str);


#endif /*MONTY_H*/
