#include "monty.h"

/**
 * pint - print the top element of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL)
		return;

	if (is_empty(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", top(*stack)->n);
}
