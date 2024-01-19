#include "monty.h"
/**
  *_rotl- rotates the stack to the top
  *@stack: stack head
  *@line_number: line_number
  *Return: nothing
 */
void _rotl(stack_t **stack,  __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp = *stack, *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	tmp = (*stack)->next;
	tmp->prev = NULL;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = temp;
	(*stack) = tmp;
}
