#include "monty.h"
/**
 * monty_pstr - prints the string starting at the top of the stack,
 * followed by a new
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
*/
void monty_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *h;
	(void)line_number;

	h = *stack;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
