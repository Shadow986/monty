#include "monty.h"

/**
 * push_stack - Function to push an element onto the stack
 * @stack: double pointer to the stack
 * @n: integer to be pushed onto the stack
 *
 * Return: void
 */
void push_stack(stack_t **stack, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}

/**
 * print_stack - Function to print all values on the stack
 * @stack: pointer to the stack
 *
 * Return: void
 */
void print_stack(stack_t *stack)
{
	while (stack != NULL)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
	}
}

/**
 * is_empty - Function to check if the stack is empty
 * @stack: pointer to the stack
 *
 * Return: 1 if the stack is empty, 0 otherwise
 */
int is_empty(stack_t *stack)
{
	return (stack == NULL);
}

/**
 * top - Function to return the top element of the stack
 * @stack: pointer to the stack
 * Return: pointer to the top element of the stack
 */
stack_t *top(stack_t *stack)
{
	if (is_empty(stack))
	{
		fprintf(stderr, "Error: stack is empty\n");
		exit(EXIT_FAILURE);
	}
	return (stack);
}
