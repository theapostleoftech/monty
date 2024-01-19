#include "monty.h"
/**
 * monty_add_node - add noe to the stack
 * @stack: stack head
 * @element: new value
 * Return: nothing
 */
void monty_add_node(stack_t **stack, int element)
{
	stack_t *new_node, *temp;

	temp = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(EXIT_SUCCESS);
	}
	if (temp)
		temp->prev = new_node;
	new_node->n = element;
	new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
}

