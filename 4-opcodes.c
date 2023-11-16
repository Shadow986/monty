#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack, followed by a new line
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void pstr(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;
    char str[1000];
    int i = 0;

    while (temp != NULL)
    {
        if (temp->n < 0 || temp->n > 127)
        {
            fprintf(stderr, "L%d: can't pstr, value out of range\n", line_number);
            exit(EXIT_FAILURE);
        }
        str[i] = temp->n;
        i++;
        temp = temp->next;
    }
    str[i] = '\0';
    printf("%s\n", str);
}

/**
 * rotl - rotates the stack to the top
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = *stack;
    *stack = temp->next;
    temp->next = NULL;
}

/**
 * rotr - rotates the stack to the bottom
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void rotr(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = *stack;
    *stack = temp;
}

/**
 * stack - sets the format of the data to a stack (LIFO)
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void stack(stack_t **stack, unsigned int line_number)
{
    /* nothing to do */
}

/**
 * queue - sets the format of the data to a queue (FIFO)
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void queue(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = *stack;
    *stack = temp;
}
