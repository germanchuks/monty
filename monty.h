#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct montyenv_s - Variables for Monty program
 * @value: Current value being processed
 * @file: Pointer to the Monty input file
 * @line_content: Content of the current line being processed
 * @mode: Flag indicating whether the program is in stack or queue mode.
 * Description: Carries values and context through the program
 */
typedef struct montyenv_s
{
	FILE *file;
	char *line_content;
	char *value;
	int mode;
} montyenv_t;
extern montyenv_t montyenv;

ssize_t getline(char **lineptr, size_t *n, FILE *stream);

/* EXECUTE OPCODE */
int run_opcode(char *line, stack_t **stack, unsigned int line_number,
	       FILE *file);

/* UTILITY FUNCTIONS */
void free_stack(stack_t *head);
void prepend(stack_t **head, int new_value);
void enqueue(stack_t **head, int new_value);

/* OPERATION OPCODES */
void push(stack_t **head, unsigned int line_number);
void pall(stack_t **head, unsigned int line_number);
void pint(stack_t **head, unsigned int line_number);
void pop(stack_t **head, unsigned int line_number);
void swap(stack_t **head, unsigned int line_number);
void add(stack_t **head, unsigned int line_number);
void nop(stack_t **head, unsigned int line_number);
void sub(stack_t **head, unsigned int line_number);
void div_opc(stack_t **head, unsigned int line_number);
void mul(stack_t **head, unsigned int line_number);
void mod(stack_t **head, unsigned int line_number);

/* CHARACTER AND STRING OUTPUT OPCODES */
void pchar(stack_t **head, unsigned int line_number);
void pstr(stack_t **head, unsigned int line_number);

/* ROT OPCODES */
void rotl(stack_t **head, unsigned int line_number);
void rotr(stack_t **head, unsigned int line_number);

/* PROGRAM MODES */
void queue_mode(stack_t **head, unsigned int line_number);
void stack_mode(stack_t **head, unsigned int line_number);

#endif /* MONTY_H */
