#define _POSIX_C_SOURCE 200809L
#include "monty.h"

/**
 * main - Monty bytecode interpreter
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error
 */
int main(int argc, char **argv)
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 1;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		if (line[0] == '#')
		{
			continue;
		}
		if (is_instruction_valid(line))
		{
			instruction_t instruction = get_instruction(line);
			instruction.f(&stack, line_number);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, line);
			exit(EXIT_FAILURE);
		}
	}
	free(line);
	fclose(file);
	return (EXIT_SUCCESS);
}
