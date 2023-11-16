#include "monty.h"

instruction_t instruction_set[] = {
	{"push", push},
	{"pall", pall},
	{"pint", pint},
	{"pop", pop},
	{"swap", swap},
	{"add", add},
	{"nop", nop},
	{"sub", sub},
	{"div", division},
	{"mul", mul},
	{"mod", mod},
	{"pchar", pchar},
	{"pstr", pstr},
	{"rotl", rotl},
	{"rotr", rotr},
	{"stack", stack},
	{"queue", queue},
	{NULL, NULL}
};

/**
 * is_instruction_valid - this is a function that checks
 * if the given line is a valid instruction
 * @line: line to check
 * Return: 1 if the line is valid, 0 otherwise
 */
int is_instruction_valid(char *line)
{
	int i;

	for (i = 0; i < 15; i++)
	{
		if (strcmp(line, instruction_set[i].opcode) == 0)
		{
			return (1);
		}
	}
	return (0);
}

/**
 * get_instruction - a function that gets the instruction from the given line
 * @line: line to get the instruction from
 * Return: instruction
 */
instruction_t get_instruction(char *line)
{
	instruction_t instruction;

	instruction.opcode = strtok(line, " ");
	instruction.f = get_instruction_function(instruction.opcode);
	return (instruction);
}

/**
 * get_instruction_function - a function that gets the function
 * associated with the given opcode
 * @opcode: opcode to get the function for
 * Return: function
 */
void (*get_instruction_function(char *opcode) (stack_t **stack, unsigned int line_number)
{
	int i;

	for (i = 0; i < 15; i++)
	{
		if (strcmp(opcode, instruction_set[i].opcode) == 0)
		{
			return (instruction_set[i].f);
		}
	}
	return (NULL);
}

/**
 * push - a function that pushes an element to the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n;
	(void)line_number;

	n = atoi(strtok(NULL, " "));

	if (n == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	stack_push(stack, n);
}

/**
 * pall - a function that prints all the values
 * on the stack, starting from the top
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
