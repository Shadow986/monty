#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: double pointer pointing to top node of the stack.
 * @line_number: Integer for the line number of of the opcode.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * nodes_swapper - Swaps top two elements of the stack.
 * @stack: double pointer pointing to top node of the stack.
 * @line_number: Integer for the line number of the opcode.
 */
void nodes_swapper(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_errors(8, line_number, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * nodes_adder - Adds top two elements of the stack.
 * @stack: double pointer pointing to top node of the stack.
 * @line_number: Integer for the line number of the opcode.
 */
void nodes_adder(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_errors(8, line_number, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * nodes_subtractor - Subtracts top two elements of the stack.
 * @stack: double pointer pointing to top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void nodes_subtractor(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_errors(8, line_number, "sub");


	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * nodes_divider - divides top two elements of the stack.
 * @stack: double pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void nodes_divider(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_errors(8, line_number, "div");

	if ((*stack)->n == 0)
		more_errors(9, line_number);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
