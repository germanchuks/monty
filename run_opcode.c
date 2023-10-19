#include "monty.h"

/**
 * run_opcode - Execute a Monty opcode command.
 * @line: The current line from the Monty program.
 * @stack: Pointer to the head of the stack (linked list).
 * @line_number: The current line number being executed.
 * @file: Pointer to the Monty file.
 *
 * This function parses and executes a Monty opcode command based on the
 * input line. It searches for a matching opcode in a list of known
 * instructions and executes it if found. If the command is not recognized,
 * it generates an error message.
 *
 * Return: 0 if the command was successfully executed, 1 if error occurs.
 */

int run_opcode(char *line, stack_t **stack, unsigned int line_number,
			   FILE *file)
{
	instruction_t instructions[] = {
		{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add},
		{"nop", nop}, {"sub", sub}, {"div", div_opc},
		{"mul", mul}, {"mod", mod}, {"pchar", pchar},
		{"pstr", pstr}, {"rotl", rotl}, {"rotr", rotr},
		{"queue", queue_mode}, {"stack", stack_mode},
		{NULL, NULL}};

	unsigned int index = 0;
	char *cmd = strtok(line, " \n\t");

	if (cmd && cmd[0] == '#')
		return (0);
	montyenv.value = strtok(NULL, " \n\t");
	while (instructions[index].opcode && cmd)
	{
		if (strcmp(cmd, instructions[index].opcode) == 0)
		{
			instructions[index].f(stack, line_number);
			return (0);
		}
		index++;
	}
	if (cmd && instructions[index].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, cmd);
		fclose(file);
		free(line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
