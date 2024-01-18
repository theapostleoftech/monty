#include "monty.h"
/**
 * monty_pop - removes the element at the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number
 * Return: nothing
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(inputs.file);
		free(inputs.line);
		monty_free(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}

