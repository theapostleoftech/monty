#include "monty.h"
/**
 * monty_mul - multiplies the top two elements of the stack.
 * @stack: stack pointer
 * @line_number: line_number
 * Return: no return
*/
void monty_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *h;
	int len = 0, tmp;

	h = *stack;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(glinput.file);
		free(glinput.line);
		monty_free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	tmp = h->next->n * h->n;
	h->next->n = tmp;
	*stack = h->next;
	free(h);
}
