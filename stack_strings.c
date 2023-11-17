#include "monty.h"

/**
 * chars_printer - Prints the Ascii value.
 * @stack: double pointer pointing to top node of the stack.
 * @line_number: Integer for the line number of the opcode.
 */
void chars_printer(stack_t **stack, unsigned int line_number)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		string_errors(11, line_number);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		string_errors(10, line_number);
	printf("%c\n", ascii);
}

/**
 * strs_printer - Prints a string.
 * @stack: doubler pointer pointing to top node of the stack.
 * @ln: Integer for the line number of the opcode.
 */
void strs_printer(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stack;
	while (temp != NULL)
	{
		ascii = temp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the first node of the stack to the bottom.
 * @stack: double pointer pointing to top node of the stack.
 * @ln: Interger for the line number of the opcode.
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotr - Rotates the last node of the stack to the top.
 * @stack: double pointer pointing to top node of the stack.
 * @ln: Interger for the line number of the opcode.
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
}
