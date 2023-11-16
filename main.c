#include "monty.h"
#define _GNU_SOURCE
#include <stdio.h>

#define _POSIX_C_SOURCE 200809L

/**
 * main - Entry point
 * @argc: The number of command line arguments
 * @argv: The command line arguments
 * Return: 0 if successful, EXIT_FAILURE otherwise
 */
int main(int argc, char **argv)
{
	FILE *file = fopen(argv[1], "r");
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	int found;
	
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}


	while ((read = getline(&line, &len, file)) != -1)
	{
		int i;
		int found = 0;
		line_number++;
		char *opcode = strtok(line, " \t\n");

		if (opcode == NULL || opcode[0] == '#')
			continue;

		for (i = 0; opcode[i].opcode != NULL; i++)
		{
			if (strcmp(opcode, opcode[i].opcode) == 0)
			{
				found = 1;
				opcode[i].f(&stack, line_number);
				break;
			}
		}

		if (!found)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			free(line);
			fclose(file);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
	}

	free(line);
	fclose(file);
	free_stack(stack);

	return (0);
}
