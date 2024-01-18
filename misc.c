#include "monty.h"
/**
 * monty_add_queue - add node to the tail stack
 * @n: new_value
 * @stack: stack of the stack
 * Return: no return
*/
void monty_add_queue(stack_t **stack, int n)
{
	stack_t *new_node, *tmp;

	tmp = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
	}
	if (!tmp)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		tmp->next = new_node;
		new_node->prev = tmp;
	}
}

#include "monty.h"
/**
 * monty_add_node - add node to the stack stack
 * @stack: stack of the stack
 * @n: new_value
 * Return: no return
*/
void monty_add_node(stack_t **stack, int n)
{

	stack_t *new_node, *tmp;

	tmp = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (tmp)
		tmp->prev = new_node;
	new_node->n = n;
	new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
}


#include "monty.h"
/**
* monty_free_stack - frees a doubly linked list
* @stack: stack of the stack
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
