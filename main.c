#include "monty.h"

/**
 * main - Entry point
 * @argc: The number of command line arguments
 * @argv: The command line arguments
 * Return: 0 if successful, EXIT_FAILURE otherwise
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	FILE *file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		char *opcode = strtok(line, " \t\n");
		if (opcode == NULL || opcode[0] == '#')
			continue;

		int found = 0;
		for (int i = 0; opcodes[i].opcode != NULL; i++)
		{
			if (strcmp(opcode, opcodes[i].opcode) == 0)
			{
				found = 1;
				opcodes[i].f(&stack, line_number);
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
