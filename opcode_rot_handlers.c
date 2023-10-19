#include "monty.h"

/**
 * rotl - Rotates the stack to move the top element to the front.
 * @head: Pointer to the head of the stack.
 * @line_number: The current line number (UNUSED).
 *
 * This function rotates the stack by moving the top element to the front.
 * If the stack is empty or contains only one element, it does nothing.
 *
 * Return: No return value.
 */

void rotl(stack_t **head, unsigned int line_number)
{
	stack_t *current_node = *head, *new_head;
	(void)line_number;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	new_head = (*head)->next;
	new_head->prev = NULL;

	while (current_node->next != NULL)
		current_node = current_node->next;

	current_node->next = *head;
	(*head)->next = NULL;
	(*head)->prev = current_node;
	(*head) = new_head;
}


/**
 * rotr - Rotates the stack to move the bottom element to the top.
 * @head: Pointer to the head of the stack.
 * @line_number: The current line number (UNUSED).
 *
 * This function rotates the stack by moving the bottom element to the top.
 * If the stack is empty or contains only one element, it does nothing.
 *
 * Return: No return value.
*/

void rotr(stack_t **head, unsigned int line_number)
{
	stack_t *current_node = *head;
	(void)line_number;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (current_node->next)
	{
		current_node = current_node->next;
	}
	current_node->next = *head;
	current_node->prev->next = NULL;
	current_node->prev = NULL;
	(*head)->prev = current_node;
	(*head) = current_node;
}
