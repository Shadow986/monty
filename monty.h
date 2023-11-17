#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*operations on files*/
void files_opener(char *file_name);
int lines_parser(char *buffer, int line_number, int format);
void files_reader(FILE *);
int char_lens(FILE *);
void funcs_finder(char *, char *, int, int);

/*operations on stack*/
stack_t *nodes_creator(int n);
void nodes_freeing(void);
void stack_printer(stack_t **, unsigned int);
void stack_adder(stack_t **, unsigned int);
void queue_adder(stack_t **, unsigned int);

void calls_func(op_func, char *, char *, int, int);

void top_printer(stack_t **, unsigned int);
void top_popper(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void nodes_swapper(stack_t **, unsigned int);

/*nodes for math operations*/
void nodes_adder(stack_t **, unsigned int);
void nodes_subtractor(stack_t **, unsigned int);
void nodes_divider(stack_t **, unsigned int);
void nodes_multiplier(stack_t **, unsigned int);
void nodes_modder(stack_t **, unsigned int);

/*operations with strings*/
void chars_printer(stack_t **, unsigned int);
void strs_printer(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
void rotr(stack_t **, unsigned int);

/*handling of errors*/
void errors(int err_code, ...);
void more_errors(int err_code, ...);
void string_errors(int err_code, ...);

#endif
