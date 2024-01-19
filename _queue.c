#include "monty.h"
/**
 * monty_add_queue - add a node to the tail
 * @stack: head of the stack
 * @element: the new value
 * Return: nothing
 */
void monty_add_queue(stack_t **stack, int element)
{
	stack_t *new_node, *temp;

	temp = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		printf("Error\n");
	new_node->n = element;
	new_node->next = NULL;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (!temp)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		temp->next = new_node;
		new_node->prev = temp;
	}
}
