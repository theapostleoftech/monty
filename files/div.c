#include "monty.h"
/**
 * monty_div - divides the top two elements of the stack.
 * @stack: pointer to the stack
 * @line_number: line_number
 * Return: no return
*/
void monty_div(stack_t **stack, unsigned int line_number)
{
	stack_t *present;
	int len = 0, tmp;

	present = *stack;
	while (present)
	{
		present = present->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		fclose(inputs.file);
		free(inputs.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	present = *stack;
	if (present->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(inputs.file);
		free(inputs.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = present->next->n / present->n;
	present->next->n = tmp;
	*stack = present->next;
	free(present);
}
