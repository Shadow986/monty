#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * push - push an element to the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n;

	if (stack == NULL)
		return;

	n = atoi(argv[1]);
	if (n == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	push_stack(stack, n);
}

/**
 * pall - print all the values on the stack, starting from the top
 * @stack: pointer to the stack
 * @line_number: line number in the file
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL)
		return;

	print_stack(*stack);
}
