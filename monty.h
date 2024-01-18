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
<<<<<<< HEAD

extern global_t vglo;

/* opcode_instc.c*/
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **doubly, unsigned int cline);
void _pop(stack_t **doubly, unsigned int cline);
void _swap(stack_t **doubly, unsigned int cline);
void _queue(stack_t **doubly, unsigned int cline);
void _stack(stack_t **doubly, unsigned int cline);
void _add(stack_t **doubly, unsigned int cline);
void _nop(stack_t **doubly, unsigned int cline);
void _sub(stack_t **doubly, unsigned int cline);
void _div(stack_t **doubly, unsigned int cline);
void _mul(stack_t **doubly, unsigned int cline);
void _mod(stack_t **doubly, unsigned int cline);
void _pchar(stack_t **doubly, unsigned int cline);
void _pstr(stack_t **doubly, unsigned int cline);
void _rotl(stack_t **doubly, unsigned int cline);
void _rotr(stack_t **doubly, unsigned int cline);

/*get function*/
void (*up_opcodes(char *opc))(stack_t **stack, unsigned int line_number);

/*imported functions*/
int _sch(char *s, char c);
char *_strtoky(char *s, char *d);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_calloc(unsigned int nmemb, unsigned int size);
int _strcmp(char *s1, char *s2);

/* doubly linked list functions */
stack_t *add_dnodeint_end(stack_t **head, const int n);
stack_t *add_dnodeint(stack_t **head, const int n);
void free_dlistint(stack_t *head);

/* main */
void free_vglo(void);

=======
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
void monty_rotl(stack_t **stack, unsigned int line_number);
void monty_rotr(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void monty_add_node(stack_t **stack, int n);
void monty_add_queue(stack_t **stack, int n);
void monty_queue(stack_t **stack, unsigned int line_number);
void monty_stack(stack_t **stack, unsigned int line_number);
>>>>>>> 1f0b48fe387b013c4b96d2973bf77ac28ebd862d
#endif
