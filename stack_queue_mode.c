#include "monty.h"

/**
 * stack_mode - Set the Monty program to stack mode.
 * @head: Pointer to the head of the stack (UNUSED)
 * @line_number: The current line number (UNUSED)
 *
 * This function sets the Monty program to stack mode, and processes commands
 * as a stack.
 *
 * Return: No return value.
 */

void stack_mode(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
	montyenv.mode = 0;
}


/**
 * queue_mode - Set the Monty program to queue mode.
 * @head: Pointer to the head of the stack (UNUSED)
 * @line_number: The current line number (UNUSED)
 *
 * This function sets the Monty program to queue mode, and processes commands
 * as a queue.
 *
 * Return: No return value.
 */

void queue_mode(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
	montyenv.mode = 1;
}
