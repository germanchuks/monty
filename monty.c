#include "monty.h"

montyenv_t montyenv = {NULL, NULL, NULL, 0};

/**
 * main - The main function of the Monty ByteCode Interpreter.
 * @argc: Number of command-line arguments.
 * @argv: An array of command-line arguments.
 * Return: 0 if successful, or an error code on failure.
 */

int main(int argc, char *argv[])
{
	char *current_line;
	FILE *monty_file;
	unsigned int line_number = 0;
	size_t line_size = 0;
	ssize_t read_status = 1;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	monty_file = fopen(argv[1], "r");
	montyenv.file = monty_file;
	if (monty_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (read_status > 0)
	{
		current_line = NULL;
		read_status = getline(&current_line, &line_size, monty_file);
		montyenv.line_content = current_line;
		line_number++;
		if (read_status > 0)
			run_opcode(current_line, &stack, line_number, monty_file);
		free(current_line);
	}

	free_stack(stack);
	fclose(monty_file);
	return (0);
}
