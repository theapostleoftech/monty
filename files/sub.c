#include "monty.h"
/**
 * monty_sub - subtracts from the stack
 * @stack: pointer to the he3ad
 * @line_number: line number
 * Return: nothing
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int sub, nodes;

	tmp = *stack;
	for (nodes = 0; tmp != NULL; nodes++)
		tmp = tmp->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(inputs.file);
		free(inputs.line);
		monty_free(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	sub = tmp->next->n - tmp->n;
	tmp->next->n = sub;
	*stack = tmp->next;
	free(tmp);
}

