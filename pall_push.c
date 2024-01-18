#include "monty.h"
/**
 * monty_pall - prints the stack
 * @stack: stack pointer
 * @line_number: no used
 * Return: no return
*/
void monty_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *h;
	(void)line_number;

	h = *stack;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * monty_push - add node to the stack
 * @stack: stack pointer
 * @line_number: line_number
 * Return: no return
*/
void monty_push(stack_t **stack, unsigned int line_number)
{
	int d, e = 0, f = 0;

	if (glinput.arg)
	{
		if (glinput.arg[0] == '-')
			e++;
		for (; glinput.arg[e] != '\0'; e++)
		{
			if (glinput.arg[e] > 57 || glinput.arg[e] < 48)
				f = 1; }
		if (f == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(glinput.file);
			free(glinput.line);
			monty_free_stack(*stack);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(glinput.file);
		free(glinput.line);
		monty_free_stack(*stack);
		exit(EXIT_FAILURE); }
	d = atoi(glinput.arg);
	if (glinput.swtch == 0)
		monty_add_node(stack, d);
	else
		monty_add_queue(stack, d);
}
