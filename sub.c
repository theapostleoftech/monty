#include "monty.h"
/**
  *monty_sub- subtration
  *@stack: stack pointer
  *@line_number: line_number
  *Return: nothing
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int s, nodes;

	tmp = *stack;
	for (nodes = 0; tmp != NULL; nodes++)
		tmp = tmp->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(glinput.file);
		free(glinput.line);
		monty_free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	s = tmp->next->n - tmp->n;
	tmp->next->n = s;
	*stack = tmp->next;
	free(tmp);
}
