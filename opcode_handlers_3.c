#include "monty.h"

/**
 * mul - Multiplies the second-top element by the top element of the stack.
 * @head: Pointer to the head of the stack.
 * @line_number: The current line number.
 *
 * This function multiplies the value of the second-top element by the top
 * element of the stack. Also handle cases where the stack is too short for
 * multiplication.
 *
 * Return: No return value.
 */

void mul(stack_t **head, unsigned int line_number)
{
	int stack_length = 0, result;
	stack_t *current_node = *head;

	while (current_node)
	{
		current_node = current_node->next;
		stack_length++;
	}
	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(montyenv.file);
		free(montyenv.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current_node = *head;
	result = current_node->next->n * current_node->n;
	current_node->next->n = result;
	*head = current_node->next;
	free(current_node);
}


/**
 * mod - Calculates the remainder of the division of the top two element of
 * the stack.
 * @head: Pointer to the head of the stack.
 * @line_number: The current line number.
 *
 * This function calculates the remainder of the division of the second-top
 * element of the stack by the top element of the stack. It also checks for
 * division by zero and handles cases where the stack is too short for the
 * operation.
 *
 * Return: No return value.
 */

void mod(stack_t **head, unsigned int line_number)
{
	int stack_length = 0, result;
	stack_t *current_node = *head;

	while (current_node)
	{
		current_node = current_node->next;
		stack_length++;
	}
	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		fclose(montyenv.file);
		free(montyenv.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current_node = *head;
	if (current_node->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(montyenv.file);
		free(montyenv.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	result = current_node->next->n % current_node->n;
	current_node->next->n = result;
	*head = current_node->next;
	free(current_node);
}
