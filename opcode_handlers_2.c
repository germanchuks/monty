#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @head: Pointer to the head of the stack.
 * @line_number: The current line number.
 *
 * This function adds the values of the top two elements of the stack
 * and handles cases where the stack is too short to perform the addition.
 *
 * Return: No return value.
 */

void add(stack_t **head, unsigned int line_number)
{
	int stack_length = 0, sum;
	stack_t *current_node = *head;

	while (current_node)
	{
		current_node = current_node->next;
		stack_length++;
	}
	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(montyenv.file);
		free(montyenv.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current_node = *head;
	sum = current_node->n + current_node->next->n;
	current_node->next->n = sum;
	*head = current_node->next;
	free(current_node);
}

/**
 * nop - Does nothing.
 * @head: Pointer to the head of the stack.
 * @line_number: The current line number.
 *
 * This function performs no operation.
 *
 * Return: No return value.
 */

void nop(stack_t **head, unsigned int line_number)
{
	(void)line_number;
	(void)head;
}


/**
 * sub - Subtracts the top element from the second-top element of the stack.
 * @head: Pointer to the head of the stack.
 * @line_number: The current line number.
 *
 * This function  subtracts the values of the two top element element of the
 * stack.
 *
 * Return: No return value.
 */

void sub(stack_t **head, unsigned int line_number)
{
	int difference, stack_length;
	stack_t *current_node = *head;

	while (current_node)
	{
		current_node = current_node->next;
		stack_length++;
	}
	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(montyenv.file);
		free(montyenv.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current_node = *head;
	difference = current_node->next->n - current_node->n;
	current_node->next->n = difference;
	*head = current_node->next;
	free(current_node);
}


/**
 * div_opc - Divides the top two elements of the stack.
 * @head: Pointer to the head of the stack.
 * @line_number: The current line number.
 *
 * This function divides the values of the two top element of the stack.
 * It handles cases of division by zero and where stack is too short for
 * division.
 *
 * Return: No return value.
 */

void div_opc(stack_t **head, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
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
	result = current_node->next->n / current_node->n;
	current_node->next->n = result;
	*head = current_node->next;
	free(current_node);
}
