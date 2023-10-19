#include "monty.h"

/**
 * push - Implements the push opcode to add a node to the stack.
 * @head: Pointer to the head of the stack.
 * @line_number: The current line number.
 *
 * This function checks if the provided value is an integer and adds a new
 * node with that value to the stack.
 *
 * Return: No return value.
 */

void push(stack_t **head, unsigned int line_number)
{
	int index = 0, invalid_value = 0, value;

	if (montyenv.value)
	{
		if (montyenv.value[0] == '-')
			index++;
		while (montyenv.value[index] != '\0')
		{
			if (montyenv.value[index] > 57 || montyenv.value[index] < 48)
			{
				invalid_value = 1;
				break;
			}
			index++;
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(montyenv.file);
		free(montyenv.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	if (invalid_value == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(montyenv.file);
		free(montyenv.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	value = atoi(montyenv.value);
	if (montyenv.mode == 0)
		prepend(head, value);
	else
		enqueue(head, value);
}

/**
 * pall - Prints the elements of the stack.
 * @head: Pointer to the head of the stack.
 * @line_number: Current line number (UNUSED).
 *
 * This function prints the elements of the stack from top to bottom.
 *
 * Return: No return value.
 */

void pall(stack_t **head, unsigned int line_number)
{
	stack_t *current_node = *head;
	(void)line_number;

	if (current_node == NULL)
		return;
	while (current_node)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}

/**
 * pint - Prints the top element of the stack.
 * @head: Pointer to the head of the stack.
 * @line_number: The current line number.
 *
 * This function prints the top element of the stack and handles
 * the case when the stack is empty.
 *
 * Return: No return value.
 */

void pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(montyenv.file);
		free(montyenv.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * pop - Removes the top element from the stack.
 * @head: Pointer to the head of the stack.
 * @line_number: The current line number.
 *
 * This function removes the top element from the stack and also
 * handles cases when the stack is empty.
 *
 * Return: No return value.
 */

void pop(stack_t **head, unsigned int line_number)
{
	stack_t *current_node;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(montyenv.file);
		free(montyenv.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current_node = *head;
	*head = current_node->next;
	free(current_node);
}

/**
 * swap - Swaps the top two elements of the stack.
 * @head: Pointer to the head of the stack.
 * @line_number: The current line number.
 *
 * This function swaps the values of the top two elements of the stack
 * and handles cases where the stack is too short to perform the swap.
 *
 * Return: No return value.
 */

void swap(stack_t **head, unsigned int line_number)
{
	int temp_val, stack_length = 0;
	stack_t *current_node = *head;

	while (current_node)
	{
		current_node = current_node->next;
		stack_length++;
	}
	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(montyenv.file);
		free(montyenv.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current_node = *head;
	temp_val = current_node->n;
	current_node->n = current_node->next->n;
	current_node->next->n = temp_val;
}
