#include "monty.h"

/**
 * instruction_set - Array of instruction structures
 *
 * Each structure in the array contains an opcode and a function pointer to
 * the function that implements the opcode. The array is terminated by a
 * sentinel structure containing NULL for both the opcode and function.
 */
instruction_t instruction_set[] = {
	/**
	 * push - Pushes an element onto the stack
	 */
	{"push", push, NULL},

	/**
	 * pall - Prints all values on the stack
	 */
	{"pall", NULL, pall},

	/**
	 * pint - Prints the value at the top of the stack
	 */
	{"pint", NULL, pint},

	/**
	 * Sentinel structure to mark the end of the array
	 */
	{NULL, NULL, NULL}
};
