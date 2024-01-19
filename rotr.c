#include "monty.h"
/**
  *monty_rotr- rotates the stack to the bottom
  *@stack: stack pointer
  *@line_number: line_number
  *Return: nothing
 */
void monty_rotr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *cpy;

	cpy = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	while (cpy->next)
	{
		cpy = cpy->next;
	}
	cpy->next = *stack;
	cpy->prev->next = NULL;
	cpy->prev = NULL;
	(*stack)->prev = cpy;
	(*stack) = cpy;
}
