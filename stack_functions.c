#include "monty.h"

<<<<<<< HEAD
=======
/**
 * stack_pop - Function to pop an element from the stack
 * @stack: double pointer to the stack
 * Return: void
 */
>>>>>>> bf9d20068c3fa4abae340b6015eddc730d2709cc
void stack_pop(stack_t **stack)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "Error: can't pop an empty stack\n");
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
<<<<<<< HEAD
=======
	{
>>>>>>> bf9d20068c3fa4abae340b6015eddc730d2709cc
		(*stack)->prev = NULL;
	free(temp);
}

<<<<<<< HEAD
=======
/**
 * stack_push - Function to push an element onto the stack
 * @stack: double pointer to the stack
 * @value: integer value to be pushed onto the stack
 * Return: void
 */
>>>>>>> bf9d20068c3fa4abae340b6015eddc730d2709cc
void stack_push(stack_t **stack, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
<<<<<<< HEAD
=======
	{
>>>>>>> bf9d20068c3fa4abae340b6015eddc730d2709cc
		(*stack)->prev = new_node;

	*stack = new_node;
}
