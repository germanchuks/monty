#include "monty.h"

/**
 * prepend - Add a new node to the head of the stack.
 * @head: head of the stack
 * @new_value: The value to be added to the new node.
 *
 * This function creates a new node with the given value and adds it to the
 * head of the stack.
 *
 * Return: No return value.
 */

void prepend(stack_t **head, int new_value)
{

	stack_t *new_node, *current_node;

	current_node = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (current_node)
	{
		current_node->prev = new_node;
	}
	new_node->n = new_value;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}

/**
 * enqueue - Add a new node to the tail of the stack.
 * @head: Pointer to the head of the stack.
 * @new_value: The value to be added to the stack.
 *
 * This function creates a new node with the given value and adds it to the
 * end of the stack. If the stack is empty, the new node becomes the head of
 * the stack.
 *
 * Return: No return value.
 */

void enqueue(stack_t **head, int new_value)
{
	stack_t *new_node, *current_node = *head;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = new_value;
	new_node->next = NULL;
	if (current_node)
	{
		while (current_node->next)
			current_node = current_node->next;
	}
	if (!current_node)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		current_node->next = new_node;
		new_node->prev = current_node;
	}
}


/**
 * free_stack - Frees a doubly linked list representing a stack.
 * @head: Pointer to the head of the stack.
 *
 * This function iterates through the doubly linked list and frees the memory
 * associated with each node.
 *
 * Return: No return value.
 */

void free_stack(stack_t *head)
{
	stack_t *current_node;

	current_node = head;
	while (head)
	{
		current_node = head->next;
		free(head);
		head = current_node;
	}
}
