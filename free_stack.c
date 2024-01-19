#include "monty.h"
/**
 * monty_free_stack - frees the stack
 * @stack: the stack to free
 * Return: nothing
 */
void monty_free_stack(stack_t *stack)
{
	stack_t *tmp;

	tmp = stack;
	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

