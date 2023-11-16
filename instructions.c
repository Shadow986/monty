#include "monty.h"

/**
 * instruction_set - Array of instruction structures
 *
 * Each structure in the array contains an opcode and a function pointer to
 * the function that implements the opcode. The array is terminated by a
 * sentinel structure containing NULL for both the opcode and function.
 */
instruction_t instruction_set[] = {
	{"push", push, NULL},

	{"pall", NULL, pall},

	{"pint", NULL, pint},

	{NULL, NULL, NULL}
};
