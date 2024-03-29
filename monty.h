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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct glinput_s - variables -args, file, line line
 * @arg: value
 * @file: pointer to monty file
 * @line: line line
 * @swtch: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct glinput_s
{
	char *arg;
	FILE *file;
	char *line;
	int swtch;
}  glinput_t;
extern glinput_t glinput;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *line);
void monty_push(stack_t **stack, unsigned int number);
void monty_pall(stack_t **stack, unsigned int number);
void monty_pint(stack_t **stack, unsigned int number);
int _run(char *line, stack_t **stack, unsigned int line_number, FILE *file);
void monty_free_stack(stack_t *head);
void monty_pop(stack_t **stack, unsigned int line_number);
void monty_swap(stack_t **stack, unsigned int line_number);
void monty_add(stack_t **stack, unsigned int line_number);
void monty_nop(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);
void monty_pchar(stack_t **stack, unsigned int line_number);
void monty_pstr(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack, unsigned int line_number);
void _rotr(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void monty_add_node(stack_t **stack, int element);
void monty_add_queue(stack_t **stack, int element);
void monty_queue(stack_t **stack, unsigned int line_number);
void monty_stack(stack_t **stack, unsigned int line_number);
#endif
