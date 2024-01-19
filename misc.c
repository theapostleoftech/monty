#include "monty.h"
/**
* monty_free_stack - function that frees a doubly linked list
* @stack: stack pointer to the stack
*
* Return: nothing
*/
void free_stack(stack_t *stack)
{
	stack_t *temp;

	temp = stack;
	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}
