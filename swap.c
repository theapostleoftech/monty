#include "monty.h"
/**
 * monty_swap - adds the top two elements of the stack.
 * @stack: stack pointer
 * @line_number: line_number
 * Return: nothing
*/
void monty_swap(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(glinput.file);
		free(glinput.line);
		monty_free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	tmp = h->n;
	h->n = h->next->n;
	h->next->n = tmp;
}
