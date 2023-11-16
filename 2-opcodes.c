#include "monty.h"

/**
 * pint - a function that prints the value at the top of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - aa function that removes the top element of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	stack_pop(stack);
}

/**
 * swap - a function that swaps the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	stack_t *temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
}

/**
 * add - a function that adds the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	int n = (*stack)->n + (*stack)->next->n;
	stack_pop(stack);
	stack_pop(stack);
	stack_push(stack, n);
}

/**
 * nop - a function that does nothing
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void nop(stack_t **stack, unsigned int line_number)
{
    /* nothing to do */
}
