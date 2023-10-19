#include "monty.h"

/**
 * pchar - Prints the character at the top of the stack.
 * @head: Pointer to the head of the stack.
 * @line_number: The current line number.
 *
 * This function prints the character at the top of the stack, followed
 * by a new line. It also checks for an empty stack and values that are out
 * of the ASCII range.
 *
 * Return: No return value.
 */
void pchar(stack_t **head, unsigned int line_number)
{
	stack_t *current_node = *head;

	if (!current_node)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(montyenv.file);
		free(montyenv.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (current_node->n > 127 || current_node->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(montyenv.file);
		free(montyenv.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", current_node->n);
}

/**
 * pstr - Prints the string starting at the top of the stack
 * @head: Pointer to the head of the stack.
 * @line_number: The current line number (UNUSED).
 *
 * This function prints the string from the top of the stack until a null byte
 * or non-ASCII character. The characters are printed without any separation.
 * The string is terminated with a newline.
 *
 * Return: No return value.
 */
void pstr(stack_t **head, unsigned int line_number)
{
	stack_t *current_node = *head;
	(void)line_number;

	while (current_node != NULL)
	{
		if (current_node->n <= 0 || current_node->n > 127)
		{
			break;
		}
		printf("%c", current_node->n);
		current_node = current_node->next;
	}
	printf("\n");
}
