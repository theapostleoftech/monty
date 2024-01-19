#include "monty.h"
/**
 * monty_add - adds the top two elements of the stack.
 * @stack: stack stack
 * @line_number: line_number
 * Return: no return
*/
void monty_add(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(glinput.file);
		free(glinput.line);
		monty_free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	tmp = h->n + h->next->n;
	h->next->n = tmp;
	*stack = h->next;
	free(h);
}
