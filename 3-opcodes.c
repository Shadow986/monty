#include "monty.h"

/**
 * sub - a function that subtracts the top element of
 * the stack from the second top element of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	int n = (*stack)->n - (*stack)->next->n;
	stack_pop(stack);
	stack_pop(stack);
	stack_push(stack, n);
}

/**
 * div - a function that divides the second top
 * element of the stack by the top element of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void div(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	int n = (*stack)->next->n / (*stack)->n;
	stack_pop(stack);
	stack_pop(stack);
	stack_push(stack, n);
}

/**
 * mul - a function that multiplies the second top
 * element of the stack with the top element of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	int n = (*stack)->n * (*stack)->next->n;
	stack_pop(stack);
	stack_pop(stack);
	stack_push(stack, n);
}

/**
 * mod - computes the rest of the division of the second top
 * element of the stack by the top element of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	int n = (*stack)->next->n % (*stack)->n;
	stack_pop(stack);
	stack_pop(stack);
	stack_push(stack, n);
}

/**
 * pchar - prints the char at the top of the stack, followed by a new line
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
