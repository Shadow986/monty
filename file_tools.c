#include "monty.h"

/**
 * files_opener - called to open a file
 * @file_name: the file namepath
 * Return: void
 */

void files_opener(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		errors(2, file_name);

	files_reader(fd);
	fclose(fd);
}


/**
 * files_reader - used for file reading
 * @fd: pointer to file descriptor
 * Return: void
 */

void files_reader(FILE *fd)
{
	int l_num, format = 0;
	char *buf = NULL;
	size_t lenth = 0;

	for (l_num = 1; getline(&buf, &lenth, fd) != -1; l_num++)
	{
		format = lines_parser(buf, l_num, format);
	}
	free(buf);
}


/**
 * lines_parser - line separator for 
 * which function to call
 * @buffer: contents of a file line
 * @line_number: line number
 * @format:  how values are stored. If 0 Nodes are stacked.
 * if 1 nodes are queued.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int lines_parser(char *buffer, int line_number, int format)
{
	char *opcodes, *val;
	const char *delimt = "\n ";

	if (buffer == NULL)
		errors(4);

	opcodes = strtok(buffer, delimt);
	if (opcodes == NULL)
		return (format);
	val = strtok(NULL, delimt);

	if (strcmp(opcodes, "stack") == 0)
		return (0);
	if (strcmp(opcodes, "queue") == 0)
		return (1);

	funcs_finder(opcodes, val, line_number, format);
	return (format);
}

/**
 * funcs_finder - finds right function for opcodes
 * @opcode: opcode to find function for
 * @value: opcode's argument
 * @format: storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void funcs_finder(char *opcode, char *value, int ln, int format)
{
	int i;
	int flag;

	instruction_t op_code_list[] = {
		{"push", stack_adder},
		{"pall", stack_printer},
		{"pint", top_printer},
		{"pop", top_popper},
		{"nop", nop},
		{"swap", nodes_swapper},
		{"add", nodes_adder},
		{"sub", nodes_subtractor},
		{"div", nodes_divider},
		{"mul", nodes_multiplier},
		{"mod", nodes_modder},
		{"pchar", chars_printer},
		{"pstr", strs_printer},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; op_code_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, op_code_list[i].opcode) == 0)
		{
			calls_func(op_code_list[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		errors(3, ln, opcode);
}


/**
 * calls_func - Calls the required function.
 * @func: Pointer to the function to be called.
 * @op: string for opcode.
 * @val: string for numeric value.
 * @ln: line number for instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void calls_func(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			errors(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				errors(5, ln);
		}
		node = nodes_creator(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			queue_adder(&node, ln);
	}
	else
		func(&head, ln);
}
