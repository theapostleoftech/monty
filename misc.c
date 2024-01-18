#include "monty.h"

/**
* monty_add_node - function that adds node to the stack stack
* @stack: stack of the stack
* @n: new value
*
* Return: nothing
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

/**
* monty_add_queue - function that add node to the tail the queue
* @n: new value
* @stack: stack of the queue
*
* Return: nothing
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
