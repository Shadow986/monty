#include "monty.h"

/**
 * nodes_multiplier - multiplies top two elements of the stack.
 * @stack: double pointer pointing to top node of the stack.
 * @line_number: Integer for the line number of the opcode.
 */
void nodes_multiplier(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_errors(8, line_number, "mul");

	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * nodes_modder - mods elements of the stack.
 * @stack: doubler pointer pointing to top node of the stack.
 * @line_number: Integer for the line number of the opcode.
 */
void nodes_modder(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_errors(8, line_number, "mod");


	if ((*stack)->n == 0)
		more_errors(9, line_number);
	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
